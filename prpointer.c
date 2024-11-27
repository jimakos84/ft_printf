/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prpointer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvlachos <dvlachos@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 13:32:59 by dvlachos          #+#    #+#             */
/*   Updated: 2024/11/26 17:23:03 by dvlachos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	prpointer(void *poi)
{
	int	i;

	i = 0;
	if (!poi)
		return (i += write(1, "(nil)", 5));
	else
	{
		i += write(1, "0x", 2);
		i += prhex((unsigned long )poi, 'x');
	}
	return (i);
}
