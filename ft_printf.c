/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvlachos <dvlachos@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 14:16:53 by dvlachos          #+#    #+#             */
/*   Updated: 2024/12/11 15:24:50 by dvlachos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check_type(const char c, va_list *args)
{
	int	i;

	i = 0;
	if (c == 'c')
		i += prchar(va_arg(*args, int));
	else if (c == 's')
		i += prstr(va_arg(*args, char *));
	else if (c == 'd' || c == 'i')
		i += prnum(va_arg(*args, int));
	else if (c == 'x' || c == 'X')
		i += prhex(va_arg(*args, unsigned int), c);
	else if (c == 'p')
		i += prpointer(va_arg(*args, void *));
	else if (c == 'u')
		i += prunsint(va_arg(*args, unsigned int));
	else if (c == '%')
		i += write(1, "%", 1);
	return (i);
}

static int	write_check(const char *c, va_list *args)
{
	int	i;
	int	check;
	int	printed;

	i = 0;
	check = 0;
	printed = 0;
	while (c[i])
	{
		if (c[i] == '%')
		{
			if (c[i + 1] == 0)
				return (-1);
			check += check_type(c[i + 1], args);
			i++;
		}
		else
			check += prchar(c[i]);
		if (check == -1)
			return (-1);
		i++;
	}
	printed = check;
	return (printed);
}

int	ft_printf(const char *c, ...)
{
	va_list	args;
	int		len;
	int		i;

	i = 0;
	len = 0;
	va_start(args, c);
	if (c == NULL)
		return (-1);
	len = write_check(c, &args);
	va_end(args);
	return (len);
}
