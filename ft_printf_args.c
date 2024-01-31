/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_args.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenez <dximenez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 15:16:41 by dximenez          #+#    #+#             */
/*   Updated: 2024/01/31 00:08:51 by dximenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_print_string(va_list *args, char c)
{
	char	*str;
	char	ch;

	str = calloc(100000, sizeof(char));
	if (c == 'c')
	{
		ch = va_arg(*args, int);
		write(1, &ch, 1);
		return (1);
	}
	else if (c == 's')
	{
		str = va_arg(*args, char *);
		write(1, str, ft_strlen(str));
		return (ft_strlen(str));
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
	char			letter;
	size_t			i;

	i = 0;
	num = va_arg(*args, unsigned int);;
	if (num == 0)
	{
		write(1, "0", 1);
		++i;
	}
	while (num > 0)
	{
		if (c == 'x')
			letter = "0123456789abcdef"[num % 16];
		else if (c == 'X')
			letter = "0123456789ABCDEF"[num % 16];
		write(1, &letter, 1);
		num = num / 16;
		++i;
	}
}
