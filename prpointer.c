/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prpointer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvlachos <dvlachos@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 13:32:59 by dvlachos          #+#    #+#             */
/*   Updated: 2024/11/25 19:14:46 by dvlachos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdint.h>
#include <stdlib.h>

static int      digit_count(unsigned long long  n)
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

int     prpnt(unsigned long long ptr)
{
        int     nmb;
        int     i;
        int     temp;
        char    hex[100];

        i = 0;
        nmb = ptr;
        while (nmb != 0)
        {
                temp = nmb % 16;
                if (temp < 10)
                        temp += 48;
                else
                        temp += 87;
                hex[i++] = temp;
                nmb /= 16;
        }
        while (hex[--i])
                write(1, &hex[i], 1);
        return (i);
}

int	prpointer(unsigned long long poi)
{
	int	i;

	i = 0;
	if (!poi)
		i += write(1, "(nil)", 6);
	else
	{
		i += write(1, "0x", 2);
		i += prpnt(poi);
	}
	return (i);
}
