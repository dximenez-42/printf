/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_args.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenez <dximenez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 15:16:41 by dximenez          #+#    #+#             */
/*   Updated: 2024/02/07 15:44:24 by dximenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_print_string(va_list *args, char c)
{
	char	*str;
	char	ch;
	size_t	len;

	if (c == 'c')
	{
		ch = va_arg(*args, int);
		write(1, &ch, 1);
		return (1);
	}
	else if (c == 's')
	{
		str = va_arg(*args, char *);
		if (str == 0)
		{
			write(1, "(null)", 6);
			return (6);
		}
		len = ft_strlen(str);
		write(1, str, len);
		return (len);
	}
	return (0);
}

size_t	ft_print_num(va_list *args, char c)
{
	int				num;
	unsigned int	uns;

	if (c == 'd' || c == 'i')
	{
		num = va_arg(*args, int);
		return (ft_putnbr_dec(num));
	}
	else if (c == 'u')
	{
		uns = va_arg(*args, unsigned int);
		return (ft_putnbr_uns(uns));
	}
	return (0);
}

size_t	ft_print_hex(va_list *args, char c)
{
	unsigned int	num;
	size_t			i;
	char			str[9];

	i = 0;
	num = va_arg(*args, unsigned int);
	if (num == 0)
		str[i++] = '0';
	while (num > 0)
	{
		if (c == 'x')
			str[i] = "0123456789abcdef"[num % 16];
		else if (c == 'X')
			str[i] = "0123456789ABCDEF"[num % 16];
		num = num / 16;
		++i;
	}
	str[i] = '\0';
	ft_reverse(str);
	write(1, str, ft_strlen(str));
	return (i);
}

size_t	ft_print_pointer(va_list *args)
{
	size_t	address;
	size_t	i;
	char	str[19];

	i = 0;
	address = va_arg(*args, size_t);
	if (address == 0)
		str[i++] = '0';
	while (address > 0)
	{
		str[i] = "0123456789abcdef"[address % 16];
		address = address / 16;
		++i;
	}
	str[i++] = 'x';
	str[i++] = '0';
	str[i] = '\0';
	ft_reverse(str);
	write(1, str, ft_strlen(str));
	return (i);
}
