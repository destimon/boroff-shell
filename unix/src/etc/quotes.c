#include "../../inc/21sh.h"

void			quote_handler(t_term *te, char *input)
{
	if (count_occ(te->query, '"') % 2 != 0)
	{
		te->quote_promptlen++;
		ft_putstr("dquote> ");
	}
	else if (count_occ(te->query, '\'') % 2 != 0)
	{
		te->quote_promptlen++;
		ft_putstr("quote> ");
	}
}