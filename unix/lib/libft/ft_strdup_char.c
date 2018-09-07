#include "libft.h"

char	    *ft_strdup_char(char c)
{
	char    *str;

    str = ft_strnew(1);
    if (str)
    {
        str[0] = c;
        return (str);
    }
	return (NULL);
}
