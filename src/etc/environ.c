/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environ.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcherend <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 15:15:14 by dcherend          #+#    #+#             */
/*   Updated: 2018/07/31 15:30:52 by dcherend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/21sh.h"

char			**get_env(void)
{
	extern char	**environ;
	char		**en;
	int			i;
	int			len;

	i = 0;
	len = ft_elems(environ);
	if (!(en = (char**)malloc((sizeof(char*) * len + 1))))
		return (NULL);
	while (environ[i])
	{
		en[i] = ft_strdup(environ[i]);
		i++;
	}
	en[i] = NULL;
	return (en);
}

char			*get_var(t_term *te, const char *var)
{
	char		*user;
	char		*tmp;
	char		*vname;
	char		*tmpvar;
	int			i;

	i = 0;
	if (!var)
		return (NULL);
	while (te->env[i])
	{
		tmpvar = ft_strdup(te->env[i]);
		vname = ft_strsub(tmpvar, 0, ft_occpos(tmpvar, '='));
		free(tmpvar);
		if (ft_strcmp(var, vname) == 0)
		{
			user = ft_strchr(te->env[i], '=');
			tmp = ft_strdup(user + 1);
			free(vname);
			return (tmp);
		}
		free(vname);
		i++;
	}
	return (NULL);
}

void			set_var(t_term *te, char *name, char *var)
{
	char		*env;
	int			i;

	i = 0;
	while (te->env[i])
	{
		if (ft_strstr(te->env[i], name))
		{
			env = ft_strjoin(name, var);
			free(te->env[i]);
			te->env[i] = env;
		}
		i++;
	}
}