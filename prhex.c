/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prhex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvlachos <dvlachos@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 17:03:09 by dvlachos          #+#    #+#             */
/*   Updated: 2024/11/25 18:17:13 by dvlachos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	prhex(long long num, char x)
{
	int	nmb;
	int	i;
	int	temp;
	char	hex[100];
	
	i = 0;
	nmb = num;
	while (nmb != 0)
	{
		temp = nmb % 16;
		if (temp < 10)
			temp += 48;
		else if (x == 'X')
			temp += 55;
		else 
			temp += 87;
		hex[i++] = temp;
		nmb /= 16;
	}
	while (hex[--i])
		write(1, &hex[i], 1);
	return (i);
}
