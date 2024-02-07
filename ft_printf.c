/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenez <dximenez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 19:44:31 by dximenez          #+#    #+#             */
/*   Updated: 2024/02/07 16:44:02 by dximenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// malloc, free, write,
// va_start, va_arg, va_copy, va_end

#include "ft_printf.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int	ft_printf(char const *f, ...)
{
	va_list	args;
	size_t	size;
	size_t	i;

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

/*
int	main(void)
{
	printf("\n\n\n");
	
	ft_printf("Hola que tal\n");
	printf("Hola que tal\n");

	printf("\n");

	ft_printf("Hola, me llamo %c y estoy haciendo el %s pero
	no se si funciona del todo bien\n", 'D', "printf");
	printf("Hola, me llamo %c y estoy haciendo el %s pero
	no se si funciona del todo bien\n", 'D', "printf");

	printf("\n");

	ft_printf("%d", -10);
	printf("%d\n", -10);

	printf("\n");

	ft_printf("Esto es una prueba de numeros %d, %i, %u\n",
	-2147483648, 2147483647, 4294967295);
	printf("Esto es una prueba de numeros %d, %i, %u\n",
	-2147483648, 2147483647, 4294967295);

	printf("\n");

	int hex = 0x52c3d;
	ft_printf("%x\n", hex);
	printf("%x\n", hex);
	printf("\n");
	ft_printf("%X\n", hex);
	printf("%X\n", hex);

	printf("\n");

	int pointer = 1823671;
	ft_printf("%p\n", &pointer);
	printf("%p\n", &pointer);

	ft_printf("%s", (char *)NULL);
	ft_printf("%p", NULL);
}

*/