/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prnum.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvlachos <dvlachos@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 12:30:12 by dvlachos          #+#    #+#             */
/*   Updated: 2024/11/28 14:58:39 by dvlachos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	digit_count(int n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n = -n;
		count++;
	}
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

int	prnum(int n)
{
	int		check;
	char	s;
	int		i;

	i = 0;
	if (n == -2147483648)
		return (write(1, "-2147483648", 11));
	if (n < 0)
	{
		i += write(1, "-", 1);
		n = -n;
	}
	if (n > 9)
	{
		check = prnum(n / 10);
		if (check == -1)
			return (-1);
	}
	s = '0' + n % 10;
	check = write(1, &s, 1);
	if (check == -1)
		return (-1);
	return (i += digit_count(n));
}
