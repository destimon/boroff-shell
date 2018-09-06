/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcherend <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 16:59:58 by dcherend          #+#    #+#             */
/*   Updated: 2018/08/06 20:38:11 by dcherend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/21sh.h"

void			key_left(t_term *te)
{
	int 		len;

	if (te->quote_promptlen == 0)
		len = te->q_iterator;
	else
		len = te->linedbuffer_length;
	if (len > 0)
	{
		te->q_iterator--;
		te->linedbuffer_length--;
		if (te->query[te->q_iterator] == '\t')
			cursor_left(TAB_SIZE);
		else
			cursor_left(1);
	}
}

void			key_right(t_term *te)
{	
	int 		len;

	if (te->quote_promptlen == 0)
		len = te->q_iterator;
	else
		len = te->linedbuffer_length;
	if (te->q_iterator < te->q_end)
	{
		te->linedbuffer_length++;
		if (te->query[te->q_iterator] == '\t')
			cursor_right(TAB_SIZE);
		else
			cursor_right(1);
		te->q_iterator++;
	}
}

void			key_up(t_term *te)
{
	int 		size;

	if (te->hst->h_iterator - 1 >= 0 && te->quote_promptlen < 1)
	{
		size = (int)ft_strlen(te->query);
		cursor_right(size - te->q_iterator);
		ft_deletechars((int)ft_strlen(te->query));
		ft_bzero(te->query, ARG_MAX);
		te->hst->h_iterator--;
		ft_strcpy(te->query, te->hst->h_ptr[te->hst->h_iterator]);
		te->q_iterator = (int)ft_strlen(te->hst->h_ptr[te->hst->h_iterator]);
		te->q_end = (int)ft_strlen(te->hst->h_ptr[te->hst->h_iterator]);
		ft_outputchars(te->hst->h_ptr[te->hst->h_iterator]);
	}
}

void			key_down(t_term *te)
{
	int 		size;

	if (te->hst->h_iterator + 1 < te->hst->h_size && te->quote_promptlen < 1)
	{
		size = (int)ft_strlen(te->query);
		cursor_right(size - te->q_iterator);
		ft_deletechars((int)ft_strlen(te->query));
		ft_bzero(te->query, ARG_MAX);
		te->hst->h_iterator++;
		ft_strcpy(te->query, te->hst->h_ptr[te->hst->h_iterator]);
		te->q_iterator = (int)ft_strlen(te->hst->h_ptr[te->hst->h_iterator]);
		te->q_end = (int)ft_strlen(te->hst->h_ptr[te->hst->h_iterator]);
		ft_outputchars(te->hst->h_ptr[te->hst->h_iterator]);
	}
}