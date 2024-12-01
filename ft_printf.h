/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshee <wshee@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 12:52:36 by wshee             #+#    #+#             */
/*   Updated: 2024/12/01 21:40:58 by wshee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <unistd.h>
#include <stdarg.h>
#include <unistd.h>

int	ft_printchar(int c);
int ft_printstr(char *s);
int ft_printaddress(void *ptr);
int	ft_printnbr(int n);
int ft_print_unsigned_nbr(unsigned n);
int ft_printhexa(unsigned long n, char print);

#endif
