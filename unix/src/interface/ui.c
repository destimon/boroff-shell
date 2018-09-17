/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcherend <dcherend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 15:08:58 by dcherend          #+#    #+#             */
/*   Updated: 2018/09/17 14:21:43 by dcherend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/21sh.h"

void			show_prompt(t_term *te)
{
	char		*user;
	char		*path;
	char		tmp[PATH_MAX];

	if (((getcwd(tmp, PATH_MAX))) != NULL)
	{
		ft_putstr("\e[1;37m[");
		if (te->shret == 1)
			ft_putstr("\e[1;32m");
		else
			ft_putstr("\e[1;31m");
		ft_putstr("X");
		ft_putstr(ANSI_COLOR_RESET);
		ft_putstr("\e[1;37m] ");
		ft_putstr(ANSI_COLOR_GREEN);
		path = path_homecut(tmp);
		ft_putstr(path);
		free(path);
		ft_putstr(ANSI_BOLD_WHITE);
		ft_putstr(" >> ");
		ft_putstr(ANSI_COLOR_RESET);
	}
}