#include "libft.h"
#include <stdio.h>

/*
** On input w/ only delims - trash in array.
*/

static int		ft_count_words(char const *str, const char *dels)
{
	int			i;

	i = 0;
	if (!ft_strchr(dels, *str) && *str != '\0')
		i++;
	while (*str)
	{
		if (ft_strchr(dels, *str) && (!ft_strchr(dels, *(str + 1)) 
		&& *(str + 1) != '\0'))
			i++;
		str++;
	}
	return (i);
}

static	int		ft_count_length(char const *str, const char *dels)
{
	int i;

	i = 0;
	while (*str && !ft_strchr(dels, *str))
	{
		i++;
		str++;
	}
	return (i);
}

static int      ft_count_delims(const char *str, const char *dels)
{
    int i;

	i = 0;
	while (*str)
	{
		if (ft_strchr(dels, *str))
			i++;
		str++;
	}
	return (i);
}

char			**ft_strsplit_smart(char const *s, const char *dels)
{
	int		word;
	char	**arr;
	int		wamount;

	word = 0;
	if (!s || !dels)
		return (NULL);
	wamount = ft_count_words(s, dels) + ft_count_delims(s, dels);
	if (!(arr = (char**)malloc(sizeof(char*) * (wamount + 1))))
		return (NULL);
	while (*s && wamount--)
	{
		if (ft_strchr(dels, *s) && *s)
		{
			while (ft_strchr(dels, *s) && *s)
			{
				arr[word++] = ft_strdup_char(*s);
				s++;
			}
		}
		else
		{
			arr[word++] = ft_strsub((const char*)s, 0, ft_count_length(s, dels));
			s = s + ft_count_length((const char*)s, dels);
		}
	}
	arr[word] = NULL;
	return (arr);
}