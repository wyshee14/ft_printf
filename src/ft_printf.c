/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshee <wshee@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 19:14:27 by wshee             #+#    #+#             */
/*   Updated: 2024/12/01 21:54:32 by wshee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int print_format(const char print, va_list args)
{
	int	i;

	i = 0;
	if (print == 'c') //char literal in C is already an int, promotion type
		i += ft_printchar(va_arg(args, int));
	else if (print == 's')
		i += ft_printstr(va_arg(args, char*));
	else if (print == 'p')
		i += ft_printaddress(va_arg(args, void*));
	else if (print == 'd' || print == 'i')
		i += ft_printnbr(va_arg(args, int));
	else if (print == 'u')
		i += ft_print_unsigned_nbr(va_arg(args, unsigned int));
	else if (print == 'x' || print == 'X')
		i += ft_printhexa(va_arg(args, int), print);
	else if (print == '%')
		i += ft_printchar('%');
	return (i);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	args;
	int	i;
	int count;

	va_start(args,fmt);
	i = 0;
	while (fmt[i] != '\0')
	{
		if (fmt[i] == '%')
		{
			i++;
			count += print_format(fmt[i], args);
		}
		else
			count += write(1, fmt, 1);
		fmt++;
	}
	va_end(args);
	return (count);
}

#include <stdio.h>

int main(void)
{
	int count = ft_printf("hello my name is %s and I am %d years old", "Laura", 23);
	printf("%d\n", count);
	printf("\n");
	printf("hello my name is %s and I am %d years old", "Laura", 23);
}
