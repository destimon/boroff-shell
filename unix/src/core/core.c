/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcherend <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 16:54:45 by dcherend          #+#    #+#             */
/*   Updated: 2018/08/06 15:53:52 by dcherend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/21sh.h"

#define HANDLED_KEYS 14

void (*g_key_handler[])(t_term *te) = {
	&key_esc,
	&key_left,
	&key_right,
	&key_up,
	&key_down,
	&key_return,
	&key_space,
	&key_backspace,
	&key_delete,
	&ctrl_d,
	&key_ctrlleft,
	&key_ctrlright,
	&key_ctrla,
	&key_ctrle
};

void			ft_bufferize(t_term *te, long input)
{
	if (ft_isprint((int)input))
	{
		tputs(tgetstr("im", NULL), 1, &complete);
		ft_putchar((char)input);
		tputs(tgetstr("ei", NULL), 1, &complete);
	}
	if (te->q_end >= ARG_MAX || !ft_isprint((int)input))
		return ;
	ft_memmove(&te->query[te->q_iterator + 1], &te->query[te->q_iterator],
			(size_t)te->q_end - te->q_iterator);
	te->query[te->q_iterator] = (char)input;
	te->q_iterator++;
	te->q_end++;
}

void			wait_input(t_term *te)
{
	int			keys[HANDLED_KEYS];
	long		input;
	int			i;

	keys[0] = KEY_ESC;
	keys[1] = L_ARROW;
	keys[2] = R_ARROW;
	keys[3] = UP_ARROW;
	keys[4] = DOWN_ARROW;
	keys[5] = KEY_RETURN;
	keys[6] = KEY_SPACE;
	keys[7] = KEY_BACK;
	keys[8] = KEY_DEL;
	keys[9] = CTRL_D;
	keys[10] = ALT_LEFT;
	keys[11] = ALT_RIGHT;
	keys[12] = CTRL_A;
	keys[13] = CTRL_E;
	input = 0;
	read(0, &input, 8);
	i = -1;
	while (++i < HANDLED_KEYS)
		if (input == keys[i])
			(*g_key_handler[i])(te);
	ft_bufferize(te, input);
}