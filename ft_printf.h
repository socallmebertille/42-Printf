/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saberton <saberton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 19:12:31 by saberton          #+#    #+#             */
/*   Updated: 2024/06/05 12:08:43 by saberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <limits.h>

# define U_MAX 4294967295
# define DEC_BASE "0123456789"
# define OCT_BASE "01234567"
# define HEX_BASE_MIN "0123456789abcdef"
# define HEX_BASE_MAJ "0123456789ABCDEF"

int	ft_printf(const char *format, ...);
int ft_check_var(char format, va_list args);
int ft_putchar(char c);
int ft_putstr(char *str);
int	ft_len_nb(long nb, int len);
int	ft_print_ptr(char *base, void *ptr, unsigned long len);
void	ft_putptr(char *base, unsigned long p, unsigned long len);
int ft_putnbr(char *base, int nbr, int len);
int	ft_putnbr_base(char *base, int nbr, int len);

#endif