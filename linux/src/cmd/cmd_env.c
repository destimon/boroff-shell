/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcherend <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/03 14:11:46 by dcherend          #+#    #+#             */
/*   Updated: 2018/08/03 14:15:25 by dcherend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/21sh.h"

void			cmd_env(t_term *te, char **args)
{
	int			i;

	i = 0;
	if (args && *args)
		if (cmd_exec(te, args[0], args))
			return ;
	while (te->env[i])
	{
		ft_putendl(te->env[i]);
		i++;
	}
}

int				cmd_resetenv(t_term *te, char *name, char *env)
{
	int			i;
	char		*tmp;

	i = 0;
	while (te->env[i])
	{
		tmp = ft_strsub(te->env[i], 0, ft_strlen(name));
		if (ft_strcmp(name, tmp) == 0)
		{
			free(te->env[i]);
			te->env[i] = ft_strdup(env);
			free(tmp);
			return (1);
		}
		free(tmp);
		i++;
	}
	return (0);
}

void			cmd_setenv(t_term *te, char **envs)
{
	int			i;
	char		*varname;
	char		*tmp;
	int			size;

	i = -1;
	while (envs[++i])
	{
		if (ft_strchr(envs[i], '=') && ft_strlen(envs[i]) > 1)
		{
			varname = var_namecut(envs[i]);
			if (ft_strlen(varname) && (tmp = get_var(te, varname)))
			{
				cmd_resetenv(te, varname, envs[i]);
				free(tmp);
			}
			else if (ft_strlen(varname))
			{
				size = ft_elems(te->env);
				te->env = realloc_env(te, (size_t)size + 1);
				te->env[size] = ft_strdup(envs[i]);
			}
			free(varname);
		}
	}
}

static int		isthere_changes(t_term *te, char **envs)
{
	int			i;
	int			count;

	count = 0;
	i = 0;
	while (te->env[i])
	{
		if (is_exist(envs, te->env[i]))
			count++;
		i++;
	}
	return (count);
}

void			cmd_unsetenv(t_term *te, char **envs)
{
	char		**new;
	int			size;
	int			i;
	int			j;
	int			elems;

	j = 0;
	i = 0;
	if (!(elems = isthere_changes(te, envs)))
		return ;
	size = ft_elems(te->env) - elems;
	new = (char**)malloc(sizeof(char*) * (size + 1));
	while (te->env[i])
	{
		if (is_exist(envs, te->env[i]) == 0)
		{
			new[j] = ft_strdup(te->env[i]);
			j++;
		}
		free(te->env[i]);
		i++;
	}
	new[size] = NULL;
	free(te->env);
	te->env = new;
}
