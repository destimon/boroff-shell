/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcherend <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 15:13:23 by dcherend          #+#    #+#             */
/*   Updated: 2018/08/06 18:01:33 by dcherend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/21sh.h"


int					search_env(t_term *te, int *i)
{
	while (te->env[++(*i)])
		if (ft_strstr(te->env[*i], "PATH="))
		{
			return (1);
		}
	return (0);
}

char			**get_envpaths(t_term *te, const char *bin)
{
	char		**paths;
	int			i;
	char		*index;
	int			check;

	i = -1;
	check = search_env(te, &i);
	if (check == 0)
		return (NULL);
	if (!(paths = ft_strsplit(ft_strchr(te->env[i], '/'), ':')))
		paths = ft_strsplit(te->env[i], ':');
	i = -1;
	while (paths && paths[++i])
	{
		index = paths[i];
		paths[i] = ft_strjoin_free(paths[i], "/", 0, 1);
		free(index);
		index = paths[i];
		paths[i] = ft_strjoin(paths[i], bin);
		free(index);
	}
	return (paths);
}

char			*path_homecut(const char *path)
{
	char		*new;
	char		*tmp;
	int			i;
	int			occ;

	i = -1;
	occ = 0;
	if (!path)
		return (NULL);
	while (path[++i])
	{
		if (path[i] == '/')
			occ++;
		if (occ == 3)
			break ;
	}
	if (occ >= 2 && ft_strstr(path, "/Users/"))
	{
		tmp = ft_strdup(&path[i]);
		new = ft_strjoin_free("~", tmp, 1, 0);
		free(tmp);
		return (new);
	}
	else
		return (ft_strdup(path));
}

char			*get_path(void)
{
	char		path[PATH_MAX];
	char		*path_ptr;
	char		*slash;

	if ((path_ptr = (getcwd(path, PATH_MAX))) != NULL)
	{
		slash = ft_strdup("/");
		path_ptr = ft_strjoin(path_ptr, slash);
		free(slash);
		return (path_ptr);
	}
	return (NULL);
}