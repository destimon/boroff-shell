/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabputs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcherend <dcherend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 09:48:12 by dcherend          #+#    #+#             */
/*   Updated: 2018/07/07 13:12:40 by dcherend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_tabputs(char *str, _Bool endl)
{
	ft_putstr("\t");
	ft_putstr(str);
	if (endl)
		ft_putendl("");
}
