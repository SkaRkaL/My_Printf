/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonctions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakarkal <sakarkal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 19:25:45 by sakarkal          #+#    #+#             */
/*   Updated: 2022/11/11 23:56:07 by sakarkal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_strlen(const char *tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (ft_putstr("(null)"));
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
	return (i);
}

int	ft_print_base_d(long long n, char *base)
{
	int	ret;

	ret = 0;
	if (n < 0)
	{
		ret += ft_putchar('-');
		n *= -1;
	}
	ret += ft_print_base_u(n, base);
	return (ret);
}

int	ft_print_base_u(unsigned long long n, char *base)
{
	int					ret;
	unsigned long long	base_len;
	int					p;

	base_len = ft_strlen(base);
	ret = 0;
	if (n >= base_len)
		ret += ft_print_base_u(n / base_len, base);
	p = write(1, &base[n % base_len], 1);
	if (p < 0)
		return (-1);
	ret++;
	return (ret);
}
