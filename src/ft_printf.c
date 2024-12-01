/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshee <wshee@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 19:14:27 by wshee             #+#    #+#             */
/*   Updated: 2024/12/01 15:43:29 by wshee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>

int print_format(char print, va_list args)
{
	int	i;

	i = 0;
	if (print == 'c') //char literal in C is already an int, promotion type
		i += ft_printchar(va_arg(args, int));
	else if (print == 's')
		i += ft_printstr(va_arg(args, char *));
	else if (print == 'p')
		i += ft_printaddress(va_arg(args, int));
	else if (print == 'd' || print == 'i')
		i += ft_printnum(va_arg(args, int));
	else if (print == 'u')
		i += ft_unsigneddecimal(va_arg(args, unsigned int));
	else if (print == 'x')
		i += ft_hexalower(va_arg(args, int));
	else if (print == 'X')
		i += ft_hexaupper(va_arg(args, int));
	else if (print == '%')
		write(1, '%', 1);
	return (i);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	args;
	int	i;

	va_start(args,fmt);
	i = 0;
	while (fmt[i] != '\0')
	{
		if (fmt[i] == '%')
		{
			print_format(fmt, args);
			i++;
		}
		else
			write(1, fmt, 1);
		fmt++;
	}
	va_end(args);
	return (s);
}

#include <stdio.h>

int main(void)
{
	//char *s = "hello my name is %s and I am %d years old";

	printf("abcd: %d", 12);
}
