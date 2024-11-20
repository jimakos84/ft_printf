/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvlachos <dvlachos@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 14:16:53 by dvlachos          #+#    #+#             */
/*   Updated: 2024/11/20 17:57:47 by dvlachos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
int	ft_putchar_fd(const char *c, int fd);
//size_t	ft_strlen(const char *str);
int	ft_putnbr_fd(int nbr);

int	prstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		write(1, &str[i++], 1);
	return (i);
}

int	prchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	check_type(const char c, va_list args)
{
	int	i;

	i = 0;
	if (c == 'c')
		i += prchar(va_arg(args, int));
	if (c == 's')
		i += prstr(va_arg(args, char *));
	if (c == 'd')
		i += ft_putnbr_fd(va_arg(args, int));	
	return (i);
		
}

int	ft_printf(const char *c, ...)
{
	va_list	args;
	int	len;
	int	i;
	
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
	return(len);
}
int	main()
{
	ft_printf("%d\n", ft_printf("%s", "helloooooo"));
	ft_printf("%c\n", 'b');
	ft_printf("%s\n", "mai+dimitris=lfe");
//	ft_printf("%d\n", ft_printf("what"));
	//printf("%d\n", ft_printf("ena"));
	//printf("%d\n", printf("royksopp"));
	return 0;
}
