/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prpointer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvlachos <dvlachos@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 13:32:59 by dvlachos          #+#    #+#             */
/*   Updated: 2024/11/29 16:57:51 by dvlachos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdint.h>

int	prpointer(void *poi)
{
	int	i;
	uintptr_t	ptr;

	i = 0;
	ptr = (uintptr_t)poi;
	if (!ptr)
		return (i += prstr("(nil)"));
	else
	{
		i += prstr("0x");
		i += prhex((uintptr_t)ptr, 'x');
	}
	return (i);
}
