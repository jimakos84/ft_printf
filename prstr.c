/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prstr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvlachos <dvlachos@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 15:13:58 by dvlachos          #+#    #+#             */
/*   Updated: 2024/11/27 16:15:23 by dvlachos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h" 

int	prstr(char *str)
{
	int	i;
	int	check;

	i = 0;
	if (str == NULL)
		return (write(1, "(null)", 6));
	while (str[i])
	{
		check = write(1, &str[i++], 1);
		if (check == -1)
			return (-1);
	}
	return (i);
}
