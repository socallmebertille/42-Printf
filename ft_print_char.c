/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saberton <saberton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 12:58:17 by saberton          #+#    #+#             */
/*   Updated: 2024/06/03 13:13:09 by saberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int ft_putchar(va_list args)
{
	char	c;

	if (!args)
		return (0);
	c = (char)args;
	write(1, &c, 1);
	return (1);
}
int	ft_pustr(va_list args)
{
	char	*str;

	if (!args)
		return (0);
	str = (char *)args;
	while(*str)
		ft_putchar(*str++);
	return (1);
}