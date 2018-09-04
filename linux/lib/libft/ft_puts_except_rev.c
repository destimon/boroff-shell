/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puts_except_rev.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcherend <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/08 12:56:22 by dcherend          #+#    #+#             */
/*   Updated: 2018/07/08 12:56:24 by dcherend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_puts_except_rev(const char *str, char ch)
{
	int			len;

	len = ft_strlen(str);
	while (len)
	{
		if (str[len] == ch)
		{
			ft_putstr(&str[len]);
			return ;
		}
		len++;
	}
}
