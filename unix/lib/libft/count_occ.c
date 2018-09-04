#include "libft.h"

int			count_occ(const char *str, char occ)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == occ)
			count++;
		i++;
	}
	return (count);
}