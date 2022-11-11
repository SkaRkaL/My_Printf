/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakarkal <sakarkal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 01:01:33 by sakarkal          #+#    #+#             */
/*   Updated: 2022/11/11 23:10:53 by sakarkal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define B16L "0123456789abcdef"
# define B16U "0123456789ABCDEF"
# define B10 "0123456789"

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>

int		ft_printf(const char *argument, ...);

int		ft_strlen(const char *tab);
int		ft_putchar(char c);
int		ft_putstr(char *str);

int		ft_print_base_d(long long n, char *base);
int		ft_print_base_u(unsigned long long n, char *base);

#endif