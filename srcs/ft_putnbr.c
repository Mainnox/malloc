/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akremer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 17:53:25 by akremer           #+#    #+#             */
/*   Updated: 2021/07/02 10:42:07 by akremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

static void		ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr_base(long nb, int b, char *base)
{
	if (nb == -2147483648)
		ft_putstr("-2147483648");
	else
	{
		if (nb < 0)
		{
			ft_putstr("-");
			nb = -nb;
		}
		if (nb >= b)
			ft_putnbr_base(nb / b, b, base);
		ft_putchar(base[nb % b]);
	}
}
