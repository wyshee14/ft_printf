/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshee <wshee@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 15:44:38 by wshee             #+#    #+#             */
/*   Updated: 2024/12/01 16:07:23 by wshee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <limits.h>
#include <unistd.h>

int	ft_printnbr(int n)
{
	int count;

	if (n == -2147483648)
	{
		ft_printchar("-");
		ft_printchar("2");
		n = 147483648;
		ft_printnbr(n);
		return(count);
	}
	if (n < 0)
	{
		ft_printchar("-");
		n = -n;
		ft_printnbr(n);
	}
	if (n < 10)
	{
		write(1, &n, 1);
		return (1);
	}
	else
	{
		count = ft_printnbr(n / 10);
		count += ft_printnbr(n % 10);
	}
}

int main(void)
{
	ft_printnbr(42);
}
