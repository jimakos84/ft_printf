/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prhex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvlachos <dvlachos@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 17:03:09 by dvlachos          #+#    #+#             */
/*   Updated: 2024/11/29 17:06:25 by dvlachos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	prmirror(char	*str)
{
	int	i;
	int	check;

	i = ft_strlen(str) - 1;
	while (str[i])
		check = write(1, &str[i--], 1);
	if (check == -1)
		return (-1);
	else
		return (0);
}

int	prhex(uintptr_t num, char x)
{
	int		i;
	int		temp;
	static char	hex[100];

	i = 0;
	if (num == 0)
		return (i += prchar('0'));
	while (num != 0)
	{
		temp = num % 16;
		if (temp < 10)
			temp += 48;
		else if (x == 'X')
			temp += 55;
		else if (x == 'x')
			temp += 87;
		hex[i++] = temp;
		num /= 16;
	}
	prmirror(hex);
	return (i);
}
