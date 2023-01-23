/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khel <ael-khel@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 16:39:04 by ael-khel          #+#    #+#             */
/*   Updated: 2023/01/22 23:13:12 by ael-khel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

typedef struct s_printf
{
	va_list	ap;
	int		len;
	int		spec;
}	t_printf;

int			ft_printf(const char *format, ...);

const char	*ft_check_spec(const char *format, t_printf *tab);

void		ft_putchar(char c, t_printf *tab);
void		ft_putstr(char *s, t_printf *tab);
void		ft_putnbr(long n, t_printf *tab);
void		ft_puthex(unsigned long n, t_printf *tab);

#endif