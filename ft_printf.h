/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvlachos <dvlachos@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 15:26:12 by dvlachos          #+#    #+#             */
/*   Updated: 2024/11/29 16:37:41 by dvlachos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdint.h>
# include <stdio.h>
# include <stdarg.h>

int	ft_printf(const char *c, ...);
int	prstr(char *str);
int	prpointer(void *poi);
int	prnum(int n);
int	prhex(unsigned long num, char x);
int	prchar(int c);
size_t	ft_strlen(const char *str);
int	prunsint(unsigned int n);

#endif
