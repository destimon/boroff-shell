/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcherend <dcherend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/08 10:20:01 by dcherend          #+#    #+#             */
/*   Updated: 2018/09/17 14:08:41 by dcherend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/21sh.h"

void			unknown_cmd(char *cmd)
{
	ft_putstr(cmd);
	ft_putendl(": unknown command");
}

void			cd_errors(char *err)
{
	if (err)
	{
		ft_putstr("cd: ");
		ft_putendl(err);
	}
}

void			bin_errors(char *err)
{
	if (err)
	{
		ft_putstr("21sh: ");
		ft_putendl(err);
	}
}