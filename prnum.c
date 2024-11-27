/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prnum.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvlachos <dvlachos@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 12:30:12 by dvlachos          #+#    #+#             */
/*   Updated: 2024/11/27 16:25:46 by dvlachos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int      digit_count(int n)
{
        int     count;

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
		prnum(n / 10);
	}
	s = '0' + n % 10;
	write(1, &s, 1);
	return (i += digit_count(n));
}
