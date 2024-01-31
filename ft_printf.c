/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenez <dximenez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 19:44:31 by dximenez          #+#    #+#             */
/*   Updated: 2024/01/31 15:28:20 by dximenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// malloc, free, write,
// va_start, va_arg, va_copy, va_end

#include "ft_printf.h"

int	ft_printf(char const *f, ...)
{
	va_list	args;
	size_t	size;
	size_t	i;
	char	*str;

	va_start(args, f);
	i = 0;
	size = 0;
	while (i < ft_strlen(f))
	{
		if (f[i] != '%')
		{
			write(1, &f[i], 1);
			++size;
		}
		else
		{
			size += ft_print_arg(f[i + 1], &args);
			++i;
		}
		++i;
	}
	va_end(args);
	return (size);
}

int	main(void)
{
	// int data = 29;
	// ft_printf("Hola, me llamo %c y estoy haciendo el %s pero no se si funciona del todo bien\n", 'D', "printf");
	// ft_printf("Esto es una prueba de numeros %d, %i, %u\n", -2147483648, 2147483647, 4294967295);
	// printf("%x\n", data); 
}
