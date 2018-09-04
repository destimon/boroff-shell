/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puts_except.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcherend <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/08 12:11:01 by dcherend          #+#    #+#             */
/*   Updated: 2018/07/08 12:11:03 by dcherend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_puts_except(const char *str, char ch)
{
	int			i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ch)
			ft_putchar(str[i]);
		i++;
	}
}
