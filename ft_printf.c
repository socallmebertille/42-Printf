/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saberton <saberton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 19:01:31 by saberton          #+#    #+#             */
/*   Updated: 2024/06/05 15:28:40 by saberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_check_var(char format, va_list args)
{
	if (format == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (format == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (format == 'p')
		return (ft_print_ptr(HEX_BASE_MIN, va_arg(args, void *), 16));
	else if (format == 'd' || format == 'i')
		return (ft_putnbr(DEC_BASE, va_arg(args, int), 10));
	else if (format == 'u')
		return (ft_putnbr_base(DEC_BASE, va_arg(args, int), 10));
	else if (format == 'x')
		return (ft_putnbr_base(HEX_BASE_MIN,va_arg(args, int), 16));
	else if (format == 'X')
		return (ft_putnbr_base(HEX_BASE_MAJ, va_arg(args, int), 16));
	else if (format == '%')
		return (ft_putchar('%'));
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
			len += ft_check_var(format[++i], args);
		else
			len += ft_putchar((char)format[i]);
		i++;
	}
	va_end(args); //free la liste de args
	return (len);
}

#include <stdio.h>
#include <limits.h>

int	main(void)
{
	char	*ptr = NULL;
	unsigned long	nb = ULONG_MAX;
	unsigned long	*p = &nb;

	printf(" %d : \n", printf("%c", '0' - 256));
	ft_printf(" %d\n", ft_printf("%c", '0' - 256));
	ft_printf("------------------------------\n");
	printf(" %d : \n", printf("%s", ptr));
	ft_printf(" %d\n", ft_printf("%s", ptr));
	ft_printf("------------------------------\n");
	printf(" %d : \n", printf("%d", 10));
	ft_printf(" %d\n", ft_printf("%d", 10));
	ft_printf("------------------------------\n");
	printf(" %d : \n", printf("%i", -101));
	ft_printf(" %d\n", ft_printf("%i", -101));
	ft_printf("------------------------------\n");
	printf(" %d : \n", printf("%u", -99));
	ft_printf(" %d\n", ft_printf("%u", -99));
	ft_printf("------------------------------\n");
	printf(" %d : \n", printf("%x", -26647485));
	ft_printf(" %d\n", ft_printf("%x", -26647485));
	ft_printf("------------------------------\n");
	printf(" %d : \n", printf("%X", 42));
	ft_printf(" %d\n", ft_printf("%X", 42));
	ft_printf("------------------------------\n");
	printf(" %d : \n", printf("%p", p));
	ft_printf(" %d \n", ft_printf("%p", p));
	ft_printf("------------------------------\n");
	printf("%% %d : \n", printf("%%"));
	ft_printf("%% %d \n", ft_printf("%%"));
	return (0);
}