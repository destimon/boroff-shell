/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit_many.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcherend <dcherend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 13:26:48 by dcherend          #+#    #+#             */
/*   Updated: 2018/09/07 18:42:12 by dcherend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_count_words(char const *str, const char *dels)
{
	int			i;

	i = 0;
	if (!ft_strchr(dels, *str) && *str != '\0')
		i++;
	while (*str)
	{
		if (ft_strchr(dels, *str) && (!ft_strchr(dels, *(str + 1)) 
		&& *(str + 1) != '\0'))
			i++;
		str++;
	}
	return (i);
}

static	int		ft_count_length(char const *str, const char *dels)
{
	int i;

	i = 0;
	while (*str != '\0' && !ft_strchr(dels, *str))
	{
		i++;
		str++;
	}
	return (i);
}

char			**ft_strsplit_many(char const *s, const char *dels)
{
	int		word;
	char	**arr;
	int		wamount;

	word = 0;
	if (s && dels)
	{
		wamount = ft_count_words(s, dels);
		arr = (char**)malloc(sizeof(*arr) * (wamount + 1));
		if (!arr)
			return (NULL);
		while (wamount--)
		{
			while (ft_strchr(dels, *s) && *s != '\0')
				s++;
			arr[word] = ft_strsub((const char*)s, 0, ft_count_length(s, dels));
			if (!arr[word])
				return (NULL);
			s = s + ft_count_length((const char*)s, dels);
			word++;
		}
		arr[word] = NULL;
		return (arr);
	}
	return (NULL);
}
