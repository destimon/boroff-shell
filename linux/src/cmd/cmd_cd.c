/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_cd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcherend <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 16:30:02 by dcherend          #+#    #+#             */
/*   Updated: 2018/08/04 16:38:56 by dcherend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/21sh.h"

static void		cd_home(t_term *te)
{
	char		*user;
	char		*tmp;

	user = get_var(te, "HOME");
	tmp = getcwd(NULL, PATH_MAX);
	set_var(te, "OLDPWD=", tmp);
	free(tmp);
	chdir(user);
	free(user);
}

static void		cd_minus(t_term *te)
{
	char		*user;
	char		*tmp;
	char		*msg;

	tmp = getcwd(NULL, PATH_MAX);
	user = get_var(te, "OLDPWD");
	if (!user)
	{
		if (tmp)
			free(tmp);
		ft_putendl("Set OLDPWD variable back, alo!");
		return ;
	}
	chdir(user);
	msg = path_homecut(user);
	if (access(user, F_OK) == 0)
		ft_putendl(msg);
	set_var(te, "OLDPWD=", tmp);
	free(user);
	if (msg)
		free(msg);
	free(tmp);
}

void			cmd_cd(t_term *te, char **dirs)
{
	char		*tmp;

	if (!dirs[0])
		cd_home(te);
	else if (ft_elems(dirs) > 1)
		return (cd_errors(ERR_CD_MANYARGS));
	else if (ft_elems(dirs) == 0 || ft_strcmp(dirs[0], "--") == 0)
		cd_home(te);
	else if (ft_strcmp(dirs[0], "-") == 0)
		cd_minus(te);
	else
	{
		tmp = getcwd(NULL, PATH_MAX);
		set_var(te, "OLDPWD=", tmp);
		free(tmp);
		if ((access(dirs[0], F_OK)) != 0)
			return (cd_errors(ERR_CD_UNEXIST));
		if ((access(dirs[0], R_OK)) != 0)
			return (cd_errors(ERR_CD_UNACCESS));
		if ((chdir(dirs[0])) == -1)
			return (cd_errors(ERR_CD_UNEXIST));
	}
}
