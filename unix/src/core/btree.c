/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcherend <dcherend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 16:02:28 by dcherend          #+#    #+#             */
/*   Updated: 2018/09/17 15:15:03 by dcherend         ###   ########.fr       */
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
	size = ft_elems(pipes);
	if (size < 3 || !pipes)
	{
		ft_putstr("Parse error\n");
		return (NULL);
	}
	start = alloc_token(pipes[i], pipes[i + 2], pipes[i + 1][0]);
	tmp = start;
	i += 2;
	while (i < size - 2)
	{
		tmp->next = alloc_token(pipes[i], pipes[i + 2], pipes[i + 1][0]);
		tmp = tmp->next;
		i += 2;
	}
	return (start);
}

int				catch_pipes(t_term *te, char *cmd)
{
	char		**pipes;
	char		delims[] = { '|', '>', '<' };
	t_token		*tok;

	pipes = ft_strsplit_smart(cmd, delims);
	if (ft_elems(pipes) < 3)
	{
		ft_free_twodm(pipes);
		return (0);
	}
	tok = get_token(pipes);
	thread_manager(te, tok);
	if (pipes)
		ft_free_twodm(pipes);
	return (1);
}
