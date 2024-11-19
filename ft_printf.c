/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvlachos <dvlachos@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 14:16:53 by dvlachos          #+#    #+#             */
/*   Updated: 2024/11/19 17:58:50 by dvlachos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
void	ft_putchar_fd(char c, int fd);

int	check_type(char ch, va_list args)
{
	int	i;

	i = 0;
	if (ch == 'c')
	{
		ft_putchar_fd(args[i], 1);
		i++;
	}
	return (i);
		
}

int	ft_printf(const char *c, ...)
{
	va_list	args;
	int	i;

	i = 0;
	va_start(args, c);
	while (c[i])
	{
		if (c[i] == '%' && c[i + 1] != '\0')
		{
				i += check_type(c[i + 1], args);
		}
		else 
		write(1, &c[i], 1);
		i++;
	}
	return(i);
}
int	main()
{
	ft_printf("%c", 'c');
	//printf("%d\n", ft_printf("ena"));
	//printf("%d\n", printf("royksopp"));
	return 0;
}
