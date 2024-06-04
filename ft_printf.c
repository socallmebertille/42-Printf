/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saberton <saberton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 19:01:31 by saberton          #+#    #+#             */
/*   Updated: 2024/06/04 20:32:26 by saberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_check_var(char format, va_list args)
{
	if (format == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (format == 's')
		return (ft_putstr(va_arg(args, char *)));
	/*else if (format == 'p')
		return (ft_print_ptrhex(args));*/
	else if (format == 'd' || format == 'i')
		return (ft_putnbr_base(DEC_BASE, va_arg(args, int), 10));
	else if (format == 'u')
		return (ft_putnbr_uns_dec(va_arg(args, int)));
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

int	main(void)
{
	char	*ptr = "Hola que tal";

	printf(" %d : \n", printf("%c", '0' - 256));
	ft_printf(" %d\n", ft_printf("%c", '0' - 256));
	printf("------------------------------\n");
	printf(" %d : \n", printf("%s", ptr));
	ft_printf(" %d\n", ft_printf("%s", ptr));
	printf("------------------------------\n");
	printf(" %d : \n", printf("%d", 10));
	ft_printf(" %d\n", ft_printf("%d", 10));
	printf("------------------------------\n");
	printf(" %d : \n", printf("%i", -101));
	ft_printf(" %d\n", ft_printf("%i", -101));
	printf("------------------------------\n");
	printf(" %d : \n", printf("%u", -1));
	ft_printf(" %d\n", ft_printf("%u", -1));
	printf("------------------------------\n");
	printf(" %d : \n", printf("%x", 0x2a));
	ft_printf(" %d\n", ft_printf("%x", 0x2a));
	printf("------------------------------\n");
	printf(" %d : \n", printf("%X", 0x2A));
	ft_printf(" %d\n", ft_printf("%X", 0x2A));
	printf("------------------------------\n");
	printf(" %d : \n", printf("%p", ptr));
	//ft_printf("%p\n", ptr);
	//printf("%% : \n", 0,10);
	//ft_printf("%%\n", 482);
	return (0);
}