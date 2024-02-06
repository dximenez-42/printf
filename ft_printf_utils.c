/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenez <dximenez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 20:11:54 by dximenez          #+#    #+#             */
/*   Updated: 2024/02/06 18:48:02 by dximenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_print_arg(char c, va_list *args)
{
	if (c == 's' || c == 'c')
		return (ft_print_string(args, c));
	else if (c == 'd' || c == 'i' || c == 'u')
		return (ft_print_num(args, c));
	else if (c == 'x' || c == 'X')
		return (ft_print_hex(args, c));
	else if (c == 'p')
		return (ft_print_pointer(args, c));
	else if (c == '%')
	{
		write(1, "%", 1);
		return (1);
	}
	return (0);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

static void	ft_putchar(char c, size_t *i)
{
	write(1, &c, 1);
	++(*i);
}

size_t	ft_putnbr_dec(int nb)
{
	size_t	i;

	i = 0;
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	else
	{
		if (nb < 0)
		{
			ft_putchar('-', &i);
			nb = -nb;
		}
		if (nb >= 10)
		{
			ft_putnbr_dec(nb / 10);
			nb = nb % 10;
		}
		if (nb < 10)
			ft_putchar(nb + '0', &i);
	}
	return (i);
}

size_t	ft_putnbr_uns(unsigned int nb)
{
	size_t	i;

	i = 0;
	if (nb >= 10)
	{
		ft_putnbr_dec(nb / 10);
		nb = nb % 10;
	}
	if (nb < 10)
		ft_putchar(nb + '0', &i);
	return (i);
}

char	*ft_reverse(char *str)
{
	int		i;
	int		size;
	char	swap;

	i = 0;
	size = ft_strlen(str) - 1;
	while (i < size)
	{
		swap = str[i];
		str[i] = str[size];
		str[size] = swap;
		++i;
		--size;
	}
	return (str);
}
