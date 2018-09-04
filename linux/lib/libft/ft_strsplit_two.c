/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit_two.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcherend <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 13:26:48 by dcherend          #+#    #+#             */
/*   Updated: 2018/07/12 13:26:50 by dcherend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_count_words(char const *str, char del, char del2)
{
	int			i;

	i = 0;
	if (*str != del && *str != del2 && *str != '\0')
		i++;
	while (*str)
	{
		if ((*str == del || *str == del2) &&
		(*(str + 1) != del && (*(str + 1) != del2 && *(str + 1) != '\0')))
			i++;
		str++;
	}
	return (i);
}

static	int		ft_count_length(char const *str, char del, char del2)
{
	int i;

	i = 0;
	while (*str != '\0' && *str != del && *str != del2)
	{
		i++;
		str++;
	}
	return (i);
}

char			**ft_strsplit_two(char const *s, char c, char c2)
{
	int		word;
	char	**arr;
	int		wamount;

	word = 0;
	if (s)
	{
		wamount = ft_count_words(s, c, c2);
		arr = (char**)malloc(sizeof(*arr) * (wamount + 1));
		if (!arr)
			return (NULL);
		while (wamount--)
		{
			while ((*s == c || *s == c2) && *s != '\0')
				s++;
			arr[word] = ft_strsub((const char*)s, 0, ft_count_length(s, c, c2));
			if (!arr[word])
				return (NULL);
			s = s + ft_count_length((const char*)s, c, c2);
			word++;
		}
		arr[word] = NULL;
		return (arr);
	}
	return (NULL);
}
