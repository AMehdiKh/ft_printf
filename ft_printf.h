/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khel <ael-khel@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 16:39:04 by ael-khel          #+#    #+#             */
/*   Updated: 2023/01/13 03:15:05 by ael-khel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

typedef struct s_printf
{
	va_list	ap;
	int		plus;
	int		minus;
	int		zero;
	int		hash;
	int		width;
	int		space;
	int		dot;
	int		prc;
	int		len;
	int		spec;
}	t_printf;

int			ft_printf(const char *format, ...);

void		ft_zero_tab(t_printf *tab);
const char	*ft_check_spec(const char *format, t_printf *tab);
const char	*ft_check_flag(const char *format, t_printf *tab);

void		ft_putchar(char c, int len, t_printf *tab);
void		ft_print_char(char c, t_printf *tab);

void		ft_putstr(char *s, int len, t_printf *tab);
void		ft_print_str(char *s, t_printf *tab);

void		ft_putnbr(long n, t_printf *tab);
void		ft_puthex(unsigned long n, t_printf *tab, char c);

#endif