/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdupch.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcherend <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 15:06:49 by dcherend          #+#    #+#             */
/*   Updated: 2018/07/10 15:06:50 by dcherend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strdupch(const char *s1, char ch)
{
	size_t		i;
	size_t		len;
	char		*s2;

	len = ft_strlench(s1, ch);
	i = 0;
	s2 = ft_strnew(len);
	if (s2)
	{
		while (i < len)
		{
			s2[i] = s1[i];
			i++;
		}
		s2[i] = '\0';
		return ((char*)s2);
	}
	return (NULL);
}
