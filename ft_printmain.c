/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printmain.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvlachos <dvlachos@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 17:23:47 by dvlachos          #+#    #+#             */
/*   Updated: 2024/11/21 17:23:58 by dvlachos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	main()
{
	int	i;
	int	*pi;
	pi = &i;
	i = 1999;
	
	ft_printf("my very own ft_printf: %x\n", i);
	printf("system's printf: %p\n", pi);
	ft_printf("my child ft_printf: %%%%%%%%\n");
	printf("robot beepboopbeep printf: %%%%%%%%\n");
	ft_printf(" best ft_printf in hive: %d\n", ft_printf("%s", "helloooooo"));
	printf(" system *yaaaaawn* printf: %d\n", printf("%s", "helloooooo"));
	printf("another system printf return: %s\n", "i thought that i heard you laughing");
	ft_printf("my ft_printf brings all the girls to the yard: %s\n", "i thought that i heard you laughing");
	ft_printf("%X\n", i);
	printf("%X\n", i);
	return 0;
}
