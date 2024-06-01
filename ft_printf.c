/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saberton <saberton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 19:01:31 by saberton          #+#    #+#             */
/*   Updated: 2024/06/01 19:29:51 by saberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_printf(const char *format, ...)
{
    int i;

    if (!format)
        return (0);
    i = 0;
	while (format[i])
    {
        if (format[i] == '%')
        {
            ft_check_var(&format[i++]);
        }
        else 
            write(1, &format[i++], 1);
    }
}