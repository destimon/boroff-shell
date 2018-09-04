/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcherend <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/04 17:45:03 by dcherend          #+#    #+#             */
/*   Updated: 2018/08/06 20:41:06 by dcherend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/21sh.h"

t_history			*init_history(void)
{
	t_history		*hst;

	hst = (t_history*)malloc(sizeof(t_history));
	if (hst)
	{
		hst->h_ptr = NULL;
		hst->h_iterator = 0;
		hst->h_size = 0;
		hst->h_capacity = 0;
		return (hst);
	}
	return (NULL);
}

char				**realloc_history(t_history *hst, int size)
{
	char			**newptr;
	int				i;

	i = 0;
	if (!(newptr = (char**)malloc(sizeof(char*) * (size + 1))))
		return (NULL);
	while (i < hst->h_size && i < size)
	{
		newptr[i] = hst->h_ptr[i];
		i++;
	}
	free(hst->h_ptr);
	return (newptr);
}

void				push_history(t_history *hst, char *cont)
{
	if (!ft_strlen(cont))
		return ;
	if (hst->h_capacity == 0)
	{
		hst->h_capacity = 10;
		if (!(hst->h_ptr = (char**)malloc(sizeof(char*) * (hst->h_capacity + 1))))
			return ;
		hst->h_ptr[hst->h_size] = ft_strdup(cont);
		hst->h_size++;
		hst->h_ptr[hst->h_size] = NULL;
		hst->h_iterator++;
	}
	else if (hst->h_capacity > hst->h_size)
	{
		hst->h_ptr[hst->h_size] = ft_strdup(cont);
		hst->h_iterator = hst->h_size + 1;
		hst->h_size++;
		hst->h_ptr[hst->h_size] = NULL;
	}
	else
	{
		hst->h_capacity = (hst->h_capacity * 2) + 1;
		hst->h_ptr = realloc_history(hst, hst->h_capacity);
		push_history(hst, cont);
	}
}