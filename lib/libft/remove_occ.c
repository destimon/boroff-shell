#include "libft.h"

char			*remove_occ(char *str, char occ)
{
	char		*dst;
	int			i;
	int			occ_len;
	int			len;
	int			j;

	j = 0;
	i = 0;
	occ_len = count_occ(str, occ);
	len = (int)ft_strlen(str) - occ_len;
	dst = ft_strnew((size_t)len);
	if (!dst)
		return (NULL);
	while (str[i])
	{
		if (str[i] != occ)
		{
			dst[j] = str[i];
			j++;
		}
		i++;
	}
	return (dst);
}