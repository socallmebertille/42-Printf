/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saberton <saberton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 11:45:43 by saberton          #+#    #+#             */
/*   Updated: 2024/06/05 15:28:30 by saberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_len_nb(long nb, int len)
{
	int	i;

	i = 1;
	if (nb < 0)
	{
		nb = -nb;
		i++;
	}
	while (nb >= len)
	{
		nb /= len;
		i++;
	}
	return (i);
}

int	ft_putnbr(char *base, int nbr, int len)
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
int ft_putnbr_base(char *base, int nbr, int len)
{
	long	nb;
	int		len_ret;
	
	nb = nbr;
	if (nbr < 0)
	{
		nb = U_MAX + nbr + 1;
		len_ret = ft_len_nb(nb, len);
	}
	else
	{
		nb = nbr;
		len_ret = ft_len_nb(nb, len);
	}
	if (nb >= len)
		ft_putnbr_base(base, nb / len, len);
	ft_putchar(base[nb % len]);
	return (len_ret);
}
void	ft_putptr(char *base, unsigned long p, unsigned long len)
{
	if (p >= len)
		ft_putptr(base, p / len, len);
	ft_putchar(base[p % len]);
}

int	ft_print_ptr(char *base, void *ptr, unsigned long len)
{
	unsigned long	p;
	int		len_ret;

	if (!ptr)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	ft_putchar('0');
	ft_putchar('x');
	p = (unsigned long )&ptr;
	len_ret = ft_len_nb(p, len) + 2;
	ft_putptr(base, p, len);
	return (len_ret);
}