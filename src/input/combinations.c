#include "../../inc/21sh.h"

void			ctrl_d(t_term *te)
{
	if (te->q_iterator + 1 < te->q_end)
	{
		te->query[te->q_iterator] = '\0';
		ft_memmove(&te->query[te->q_iterator + 1], &te->query[te->q_iterator],
				   (size_t)te->q_end - te->q_iterator);
		te->q_end--;
		tputs(tgetstr("dc", NULL), 1, &complete);
	}
	else if (te->q_iterator == 0)
	{
		te->query[te->q_iterator] = '\0';
	}
}