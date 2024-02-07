/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenez <dximenez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 19:45:20 by dximenez          #+#    #+#             */
/*   Updated: 2024/02/07 16:43:32 by dximenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

// # include "../libft/libft.h"
# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>
# include <stdlib.h>

int		ft_printf(char const *f, ...);
size_t	ft_print_arg(char c, va_list *args);
size_t	ft_print_string(va_list *args, char c);
size_t	ft_print_num(va_list *args, char c);
size_t	ft_print_hex(va_list *args, char c);
size_t	ft_print_pointer(va_list *args);

size_t	ft_strlen(const char *s);
size_t	ft_putnbr_dec(int nb);
size_t	ft_putnbr_uns(unsigned int nb);
char	*ft_reverse(char *str);

#endif