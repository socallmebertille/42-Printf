/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saberton <saberton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 19:01:31 by saberton          #+#    #+#             */
/*   Updated: 2024/06/03 14:04:06 by saberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int ft_check_var(char format, va_list args, int len)
{
	if (format == 'c')
		return (ft_putchar(args));
	else if (format == 's')
		return (ft_putstr(args));
	else if (format == 'p')
		return (ft_print_ptrhex(args));
	else if (format == 'd')
		return (ft_putnbr_dec(args));
	else if (format == 'i')
		return (ft_putnbr_int(args));
	else if (format == 'u')
		return (ft_prutnbr_uns_dec(args));
	else if (format == 'x')
		return (ft_print_numhexlow(args));
	else if (format == 'X')
		return (ft_print_numhexupp(args));
	else if (format == '%')
		return (ft_print_percent(args));
	else
		return (0);
}

int	ft_printf(const char *format, ...)
{
	int i; //i eme 
	int len; //len ieme args
	va_list args; //liste variable d'arguments

	if (!format)
		return (0);
	i = 0;
	len = 0;
	va_start(args, format); //init list de args apres format
	while (format[i])
	{
		if (format[i] == '%')
			len += ft_check_var(format[++i], args, len);
		else
			ft_putchar(format[i]); 
		i++;
	}
	va_end(args); //free la liste de args
	return (len);
}

#include <stdio.h>

int	main(void)
{
	printf("%c", 'c');
	ft_printf("%c", 'c');
	return (0);
}