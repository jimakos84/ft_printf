/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvlachos <dvlachos@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 14:16:53 by dvlachos          #+#    #+#             */
/*   Updated: 2024/11/29 16:32:41 by dvlachos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_type(const char c, va_list args)
{
	int	i;

	i = 0;
	if (c == 'c')
		i += prchar(va_arg(args, int));
	else if (c == 's')
		i += prstr(va_arg(args, char *));
	else if (c == 'd' || c == 'i')
		i += prnum(va_arg(args, int));
	else if (c == 'x' || c == 'X')
		i += prhex(va_arg(args, unsigned int), c);
	else if (c == 'p')
		i += prpointer(va_arg(args, void *));
	else if (c == 'u')
		i += prunsint(va_arg(args, unsigned int));
	else if (c == '%')
		i += write(1, "%", 1);
	else if (c == '\0')
		return (-1);
	return (i);
}

int	ft_printf(const char *c, ...)
{
	va_list	args;
	int		len;
	int		i;

	i = 0;
	len = 0;
	va_start(args, c);
	while (c[i])
	{
		if (c[i] == '%')
		{
			len += check_type(c[i + 1], args);
			i++;
		}
		else
			len += prchar(c[i]);
		i++;
	}
	va_end(args);
	return (len);
}
