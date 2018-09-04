/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcherend <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 15:17:12 by dcherend          #+#    #+#             */
/*   Updated: 2018/07/09 15:17:15 by dcherend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_realloc(char *ptr, size_t size)
{
	char	*new;
	int		i;

	i = 0;
	new = (char*)malloc(size);
	if (!new)
		return (NULL);
	ft_bzero(new, size);
	while (ptr[i])
	{
		new[i] = ptr[i];
		i++;
	}
	free(ptr);
	return (new);
}
