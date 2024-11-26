/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvlachos <dvlachos@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 14:16:53 by dvlachos          #+#    #+#             */
/*   Updated: 2024/11/26 17:13:43 by dvlachos         ###   ########.fr       */
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
		i += prpointer(va_arg(args, void *));
	if (c == 'u')
		i += prnum(va_arg(args, unsigned long));
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
	int	num;
	int	m;
	int	*i;
	int	*e;

	num = 4182306;	
	m = 0;
	i = &num;
	e = i;
	ft_printf("---ooo------------------------------oo---------------ooo-----------------------------------------------------------\n");
	ft_printf("--oo-oo------------oo--oo-----------oo--------------oo-oo----------------------------------------------------------\n");
	ft_printf("--oo-oo------------oo---oo--------------------------oo-oo----------------------------------------------------------\n");
	ft_printf("--oo-----oo--------oo---oo--oo-oo---oo-oo-oo----oo--oo-------------------------------------------------------------\n");
	ft_printf("--oooo--oooo-------oo---oo--oo---oo-oo-oo---oo-oooo-oooo-----------------------------------------------------------\n");
	ft_printf("--oo-----oo--------oo-oo----oo------oo-oo---oo--oo--oo-------------------------------------------------------------\n");
	ft_printf("--oo-----oo--------oo-------oo------oo-oo---oo--oo--oo-------------------------------------------------------------\n");
	ft_printf("--oo-----ooo-ooooo-oo-------oo------oo-oo---oo--ooo-oo-------------------------------------------------------------\n");
	printf("system's printf: %d\n", num);
	ft_printf("my ft_printf: %d\n", num);
	ft_printf("-------------------------------------------------------------------------------------------------------------------\n");
        ft_printf("my ft_printf: %%%%%%%%\n");
        printf("system printf: %%%%%%%%\n");
	ft_printf("-------------------------------------------------------------------------------------------------------------------\n");
        ft_printf(" my ft_printf: %d\n", ft_printf("%s", "helloooooo"));
        printf(" system printf: %d\n", printf("%s", "helloooooo"));
	ft_printf("-------------------------------------------------------------------------------------------------------------------\n");
        printf("system printf: %s\n", "i thought that i heard you laughing");
        ft_printf("my ft_printf: %s\n", "i thought that i heard you laughing");
	ft_printf("-------------------------------------------------------------------------------------------------------------------\n");
        ft_printf("%d\n", ft_printf("my hexadecimal: %x\n", num));
        printf("%d\n", printf("sy hexadecimal: %x\n", num));
	ft_printf("-------------------------------------------------------------------------------------------------------------------\n");
	ft_printf("my ft_printf: %X\n", num);
        printf("system's printf: %X\n", num);
	ft_printf("-------------------------------------------------------------------------------------------------------------------\n");
	ft_printf("here is a char: %c\n", 'm');
	printf("here is another char: %c\n", 'd');
	ft_printf("-------------------------------------------------------------------------------------------------------------------\n");
	ft_printf("my ft_printf: %d\n", ft_printf("mine: %p\n", i));
	printf("sys's printf: %d\n", printf("syst: %p\n", i));
	ft_printf("-------------------------------------------------------------------------------------------------------------------\n");

        return 0;
}
