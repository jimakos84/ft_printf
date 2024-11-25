/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvlachos <dvlachos@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 14:16:53 by dvlachos          #+#    #+#             */
/*   Updated: 2024/11/25 18:00:16 by dvlachos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
	if (c == 'x' || c == 'X')
		i += prhex(va_arg(args, int), c);
	if (c == 'p')
		i += prpointer(va_arg(args, unsigned long long));
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

int     main()
{
	int	m;
	int	*i;
	
	m = 1999;
	i = &m;
        ft_printf("my ft_printf: %%%%%%%%\n");
        printf("system printf: %%%%%%%%\n");
        ft_printf(" my ft_printf: %d\n", ft_printf("%s", "helloooooo"));
        printf(" system printf: %d\n", printf("%s", "helloooooo"));
        printf("system printf: %s\n", "i thought that i heard you laughing");
        ft_printf("my ft_printf: %s\n", "i thought that i heard you laughing");
        ft_printf("%x\n", m);
        printf("%x\n", m);
	ft_printf("here is a char: %c\n", 'm');
	printf("here is another char: %c\n", 'd');
	ft_printf("my ft_printf with pointer: %p\n", i);
	printf("system printf with pointer: %p\n", i);
        return 0;
}
