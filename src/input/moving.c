#include "../../inc/21sh.h"

void		key_ctrlleft(t_term *te)
{
	int		i;

	i = 0;
	if ((te->query[te->q_iterator - 1] == ' ' ||
	te->query[te->q_iterator - 1] == '\t' ||
	te->query[te->q_iterator - 1] == ';')
	&& te->q_iterator > 0)
	{
		te->q_iterator--;
		cursor_left(1);
	}
	while (te->q_iterator > 0)
	{
		if (te->query[te->q_iterator - 1] == ' ' ||
			te->query[te->q_iterator - 1] == '\t' ||
			te->query[te->q_iterator - 1] == ';')
			break;
		te->q_iterator--;
		i++;
	}
	cursor_left(i);
}

void		key_ctrlright(t_term *te)
{
	int		i;

	i = 0;
	while (te->q_iterator < te->q_end - 1)
	{
		if (te->query[te->q_iterator] == ' ' ||
		te->query[te->q_iterator] == '\t' ||
		te->query[te->q_iterator] == ';')
			break;
		i++;
		te->q_iterator++;
	}
	if (te->q_end > 0 && (te->q_iterator < te->q_end))
	{
		te->q_iterator++;
		cursor_right(i + 1);
	}
}

void		key_ctrle(t_term *te)
{
	cursor_right(te->q_end - te->q_iterator);
	te->q_iterator = te->q_end;
}

void		key_ctrla(t_term *te)
{
	cursor_left(te->q_iterator);
	te->q_iterator = 0;
}