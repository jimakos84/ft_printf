/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prhex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvlachos <dvlachos@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 17:03:09 by dvlachos          #+#    #+#             */
/*   Updated: 2024/12/09 11:49:56 by dvlachos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	prmirror(char	*str)
{
	int	total_digits;
	int	significant_digits;
	int	check;
	int	i;

	total_digits = ft_strlen(str) - 1;
	significant_digits = 0;
	while (total_digits >= 0)
	{
		if (str[total_digits] != '0')
		{
			significant_digits = total_digits + 1;
			break ;
		}
	}
	i = significant_digits - 1;
	while (i >= 0)
	{
		check = prchar(str[i]);
		if (check == -1)
			return (-1);
		i--;
	}
	return (significant_digits);
}

int	prhex(uintptr_t num, char x)
{
	int			i;
	uintptr_t	temp;
	static char	hex[100];

	i = 0;
	if (num == 0)
		return (i += prchar('0'));
	while (num != 0)
	{
		temp = num % 16;
		if (temp < 10)
			hex[i] = temp + 48;
		else if (x == 'X')
			hex[i] = temp + 55;
		else if (x == 'x')
			hex[i] = temp + 87;
		i++;
		num /= 16;
	}
	hex[i] = '\0';
	return (prmirror(hex));
}
