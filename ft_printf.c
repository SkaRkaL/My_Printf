/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakarkal <sakarkal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 19:28:11 by sakarkal          #+#    #+#             */
/*   Updated: 2022/11/11 23:59:21 by sakarkal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_kteeb(va_list *args, char c)
{
	int	count;

	count = 0;
	if (c == '%')
		count += ft_putchar(c);
	else if (c == 'c')
		count += ft_putchar(va_arg(*args, int));
	else if (c == 'd' || c == 'i')
		count += ft_print_base_d(va_arg(*args, int), B10);
	else if (c == 'u')
		count += ft_print_base_u(va_arg(*args, unsigned int), B10);
	else if (c == 'p')
		count += (ft_putstr("0x") + ft_print_base_u(\
			va_arg(*args, unsigned long int), B16L));
	else if (c == 's')
		count += ft_putstr(va_arg(*args, char *));
	else if (c == 'x')
		count += ft_print_base_u(va_arg(*args, unsigned int), B16L);
	else if (c == 'X')
		count += ft_print_base_u(va_arg(*args, unsigned int), B16U);
	else
		count += ft_putchar(c);
	return (count);
}

int	ft_printf(const char *formt, ...)
{
	va_list	ptr;
	int		i;
	int		len;

	len = 0;
	i = -1;
	va_start(ptr, formt);
	while (formt[++i])
	{
		if (formt[i] == '%')
		{
			if (formt[i + 1] == '\0')
				break ;
			len += ft_kteeb(&ptr, formt[i + 1]);
			i++;
		}
		else
			len += ft_putchar(formt[i]);
	}
	va_end(ptr);
	return (len);
}
