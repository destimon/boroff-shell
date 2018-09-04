/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcherend <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 16:50:02 by dcherend          #+#    #+#             */
/*   Updated: 2018/08/06 17:53:53 by dcherend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/21sh.h"

void			key_esc(t_term *te)
{

}

void			key_return(t_term *te)
{
	char		**cmds;
	int			i;

	i = -1;
	ft_putchar('\n');
	if (count_occ(te->query, '"') % 2 != 0 ||
			count_occ(te->query, '\'') % 2 != 0)
	{
		quote_handler(te, te->query);
		te->query[te->q_end] = '\n';
		te->q_iterator++;
		te->q_end++;
	}
	else
	{
		push_history(te->hst, te->query);
		cmds = ft_strsplit(te->query, ';');
		while (cmds[++i])
			commands_space(te, cmds[i]);
		while (cmds[i])
			free(cmds[i--]);
		te->q_iterator = 0;
		te->q_end = 0;
		ft_bzero(te->query, ARG_MAX);
		free(cmds);
		show_prompt(te);
	}
}

void			key_space(t_term *te)
{

}

void			key_backspace(t_term *te)
{
	if (te->q_iterator > 0)
	{
		te->q_iterator--;
		te->query[te->q_iterator] = '\0';
		ft_memmove(&te->query[te->q_iterator], &te->query[te->q_iterator + 1],
				(size_t)te->q_end - te->q_iterator);
		te->q_end--;
		tputs(tgetstr("le", NULL), 1, &complete);
		tputs(tgetstr("dc", NULL), 1, &complete);
	}
	else if (te->q_iterator == 1)
	{
		ft_memmove(&te->query[0], &te->query[1],
				   (size_t)te->q_end - te->q_iterator);
	}
}

void			key_delete(t_term *te)
{

}