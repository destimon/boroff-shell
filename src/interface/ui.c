/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcherend <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 15:08:58 by dcherend          #+#    #+#             */
/*   Updated: 2018/08/04 14:38:32 by dcherend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/21sh.h"

void			show_prompt(t_term *te)
{
	char		*user;
	char		*path;
	char		tmp[PATH_MAX];
	char		host[1024];

	user = get_var(te, "USER");
	if (((getcwd(tmp, PATH_MAX))) != NULL)
	{
		gethostname(host, 1024);
		ft_putstr(ANSI_COLOR_GREEN);
		ft_putstr(user);
		free(user);
		ft_putstr("@");
		ft_putstr(ANSI_COLOR_GREEN);
		ft_putstr(host);
		ft_putstr(":");
		ft_putstr(ANSI_COLOR_BLUE);
		path = path_homecut(tmp);
		ft_putstr(path);
		free(path);
		ft_putstr(ANSI_BOLD_WHITE);
		ft_putstr("$> ");
		ft_putstr(ANSI_COLOR_RESET);
	}
}