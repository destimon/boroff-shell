/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcherend <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 16:02:28 by dcherend          #+#    #+#             */
/*   Updated: 2018/09/06 16:02:58 by dcherend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/21sh.h"

static t_token	*alloc_token(char *left, char *right, int op)
{
	t_token		*tok;

	tok = (t_token*)malloc(sizeof(t_token));
	if (tok)
	{
		tok->left = left;
		tok->right = right;
		tok->op = op;
		tok->next = NULL;
		return (tok);
	}
	return (NULL);
}

static t_token	*get_token(char **pipes)
{
	t_token		*start;
	t_token		*tmp;
	int			i;
	int			size;

	i = 0;
	start = alloc_token(pipes[i], pipes[i + 1], B_PIPE);
	tmp = start;
	size = ft_elems(pipes);
	i += 1;
	while (i < size - 1)
	{
		tmp->next = alloc_token(pipes[i], pipes[i + 1], B_PIPE);
		tmp = tmp->next;
		i++;
	}
	return (start);
}

static void		init_pipethreads(t_term *te, t_token *tok)
{
	char		**cmd;
	int			pipefd[2];
	pid_t		pid;

	pipe(pipefd);
	pid = fork();
	if (pid == 0)
	{
		dup2(pipefd[0], 0);
		close(pipefd[1]);
		execve("ls", &tok->left, te->env);
		dup2(pipefd[1], 1);
		close(pipefd[0]);
		execve("ls", &tok->left, te->env);
	}
	else if (pid < 0)
		ft_putendl("Unable to fork pid");
}

int				catch_pipes(t_term *te, char *cmd)
{
	char		**pipes;
	t_token		*tok;
	t_token		*tmp;

	pipes = ft_strsplit(cmd, '|');
	if (ft_elems(pipes) < 2)
	{
		ft_free_twodm(pipes);
		return (0);
	}
	tok = get_token(pipes);
	init_pipethreads(te, tok);
	while (tok)
	{
		tmp = tok;
		tok = tok->next;
		free(tmp);
	}
	ft_free_twodm(pipes);
	return (1);
}
