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

int				catch_pipes(char *cmd)
{
	char		**pipes;
	t_token		*tok;

	pipes = ft_strsplit(cmd, '|');
	if (ft_elems(pipes) < 2)
	{
		ft_free_twodm(pipes);
		return (0);
	}
	tok = get_token(pipes);
	while (tok)
	{
		printf("left: %s\n", tok->left);
		printf("right: %s\n", tok->right);
		tok = tok->next;
	}
	ft_free_twodm(pipes);
	return (1);
}