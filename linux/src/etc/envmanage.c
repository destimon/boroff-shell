/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envmanage.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcherend <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/11 11:55:03 by dcherend          #+#    #+#             */
/*   Updated: 2018/08/02 18:05:21 by dcherend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/21sh.h"

char			**realloc_env(t_term *te, size_t size)
{
	char		**new;
	int			i;

	i = 0;
	new = (char**)malloc(sizeof(char*) * (size + 1));
	while (te->env[i])
	{
		new[i] = ft_strdup(te->env[i]);
		free(te->env[i]);
		i++;
	}
	while (i < (int)size)
	{
		new[i] = NULL;
		i++;
	}
	new[size] = NULL;
	free(te->env);
	te->env = new;
	return (new);
}

int				is_exist(char **todel, char *env)
{
	char		*cut;
	int			i;

	cut = var_namecut(env);
	i = 0;
	while (todel[i])
	{
		if (ft_strcmp(todel[i], cut) == 0)
		{
			free(cut);
			return (1);
		}
		i++;
	}
	free(cut);
	return (0);
}
