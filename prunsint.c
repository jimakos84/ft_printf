/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prunsint.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvlachos <dvlachos@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 13:02:50 by dvlachos          #+#    #+#             */
/*   Updated: 2024/11/27 16:39:25 by dvlachos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int      digit_count(unsigned int n)
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

int	prunsint(unsigned int	n)
{
	char	s;

	if (n > 9)
	{
		prunsint(n / 10);
	}
	s = '0' + n % 10;
	write(1, &s, 1);
	return (digit_count(n));
}