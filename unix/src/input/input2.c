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
	if (te->q_iterator > 0)
	{
		te->q_iterator--;
		tputs(tgetstr("le", NULL), 1, &complete);
	}
}

void			key_right(t_term *te)
{
	if (te->q_iterator < te->q_end)
	{
		te->q_iterator++;
		tputs(tgetstr("nd", NULL), 1, &complete);
	}
}

void			key_up(t_term *te)
{
	if (te->hst->h_iterator - 1 >= 0)
	{
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
	if (te->hst->h_iterator + 1 < te->hst->h_size)
	{
		ft_deletechars((int)ft_strlen(te->query));
		ft_bzero(te->query, ARG_MAX);
		te->hst->h_iterator++;
		ft_strcpy(te->query, te->hst->h_ptr[te->hst->h_iterator]);
		te->q_iterator = (int)ft_strlen(te->hst->h_ptr[te->hst->h_iterator]);
		te->q_end = (int)ft_strlen(te->hst->h_ptr[te->hst->h_iterator]);
		ft_outputchars(te->hst->h_ptr[te->hst->h_iterator]);
	}
}