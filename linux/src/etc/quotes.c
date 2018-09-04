#include "../../inc/21sh.h"

void			quote_handler(t_term *te, char *input)
{
	if (count_occ(te->query, '"') % 2 != 0)
	{
		ft_putstr("dquote> ");
	}
	else if (count_occ(te->query, '\'') % 2 != 0)
	{
		ft_putstr("quote> ");
	}
}