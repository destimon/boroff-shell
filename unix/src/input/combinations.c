#include "../../inc/21sh.h"

void			ctrl_d(t_term *te)
{
	int 		len;

	len = 0;
	if (ft_strlen(te->query) == 0)
	{
		ft_putchar('\n');
		reset_input_mode();
		exit(0);
	}
	if (te->quote_promptlen == 0)
		len = te->q_iterator;
	else
		len = te->linedbuffer_length;
	if (len > 0)
	{
		te->q_iterator--;
		te->linedbuffer_length--;
		te->query[te->q_iterator] = '\0';
		ft_memmove(&te->query[te->q_iterator], &te->query[te->q_iterator + 1],
				(size_t)te->q_end - te->q_iterator);
		te->q_end--;
		tputs(tgetstr("le", NULL), 1, &complete);
		tputs(tgetstr("dc", NULL), 1, &complete);
	}
	else if (len == 1)
	{
		ft_memmove(&te->query[0], &te->query[1],
				   (size_t)te->q_end - te->q_iterator);
	}
}