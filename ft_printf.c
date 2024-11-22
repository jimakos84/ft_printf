/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvlachos <dvlachos@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 14:16:53 by dvlachos          #+#    #+#             */
/*   Updated: 2024/11/21 17:23:07 by dvlachos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>

int	prstr(char *str);
int	prnum(int nbr);
int	prchar(int c);
int	putnbrbase(int nbr, char *base);

int	check_type(const char c, va_list args)
{
	int	i;

	i = 0;
	if (c == 'c')
		i += prchar(va_arg(args, int));
	if (c == 's')
		i += prstr(va_arg(args, char *));
	if (c == 'd' || c == 'i')
		i += prnum(va_arg(args, int));
	if (c == 'x')
		i += putnbrbase(va_arg(args, int), "0123456789abcdef");
	if (c == 'X')
		i += putnbrbase(va_arg(args, int), "0123456789ABCDEF");
	if (c == '%')
		i += write(1, "%", 1);
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
