/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   qu_deleter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcherend <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 20:22:17 by dcherend          #+#    #+#             */
/*   Updated: 2018/08/06 20:23:33 by dcherend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/21sh.h"

void		ft_outputchars(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (ft_isprint((int)str[i]))
		{
			tputs(tgetstr("im", NULL), 1, &complete);
			ft_putchar(str[i]);
			tputs(tgetstr("ei", NULL), 1, &complete);
		}
		i++;
	}
}

void		ft_deletechars(int size)
{
	int		i;

	i = 0;
	while (i < size)
	{
		tputs(tgetstr("le", NULL), 1, &complete);
		tputs(tgetstr("dc", NULL), 1, &complete);
		i++;
	}
}