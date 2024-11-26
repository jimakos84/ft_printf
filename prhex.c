/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prhex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvlachos <dvlachos@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 17:03:09 by dvlachos          #+#    #+#             */
/*   Updated: 2024/11/26 16:23:02 by dvlachos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

void	prmirror(char	*str)
{
	int	i;

	i = ft_strlen(str) - 1;
	while (str[i])
		write(1, &str[i--], 1);
}

int	prhex(unsigned long num, char x)
{
	int		i;
	int		temp;
	char	*hex;

	i = 0;
	hex = malloc(100);
	if (num == 0)
		return (i += write(1, "0", 1));
	while (num != 0)
	{
		temp = num % 16;
		if (temp < 10)
			temp += 48;
		else if (x == 'X')
			temp += 55;
		else
			temp += 87;
		hex[i++] = temp;
		num /= 16;
	}
	prmirror(hex);
	free(hex);
	return (i);
}
