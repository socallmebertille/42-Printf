/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saberton <saberton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 11:45:43 by saberton          #+#    #+#             */
/*   Updated: 2024/06/04 20:35:11 by saberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_len_nb(int nbr, int len)
{
	int	i;
	long	nb;

	i = 1;
	nb = nbr;
	if (nb < 0)
	{
		nb = -nb;
		i++;
	}
	while (nb > len)
	{
		nb /= len;
		i++;
	}
	return (i);
}

int	ft_putnbr_base(char *base, int nbr, int len)
{
	long	nb;

	nb = nbr;
	if (nb < 0)
	{
			ft_putchar('-');
			nb = -nb;
	}
	if (nb >= len)
			ft_putnbr_base(base, nb / len, len);
	ft_putchar(base[nb % len]);
	return (ft_len_nb(nbr, len));
}
int ft_putnbr_uns_dec(unsigned int u)
{
	unsigned int	nb;
	
	nb = u;
	if (u < 0)
		nb = U_MAX - u;
	if (nb >= 10)
			ft_putnbr_uns_dec(nb / 10);
	ft_putchar(nb % 10 + '0');
	return (ft_len_nb(u, 10));
}