/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcherend <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 13:41:26 by dcherend          #+#    #+#             */
/*   Updated: 2018/03/31 13:45:37 by dcherend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_is_prime(int nb)
{
	int	d;

	if (nb % 2 == 0)
		return (nb == 2);
	d = 3;
	while ((d * d <= nb) && (nb % d != 0))
		d += 2;
	return (d * d > nb);
}
