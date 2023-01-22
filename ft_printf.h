/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khel <ael-khel@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 16:39:04 by ael-khel          #+#    #+#             */
/*   Updated: 2023/01/22 04:19:21 by ael-khel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>

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

char		*ft_hextoa(unsigned long n, t_printf *tab);
int			ft_hexlen(unsigned long n, t_printf *tab);

char		*ft_itoa_base(long n, int base, t_printf *tab);
int			ft_nbrlen(long n, int base, t_printf *tab);

void		ft_print_ptr(unsigned long n, t_printf *tab);
void		ft_print_hex(unsigned int n, t_printf *tab);
void		ft_check_hex(char	*hex, int len, t_printf *tab);

char		*ft_strchr(const char *s, int c);
int			ft_isdigit(int c);
size_t		ft_strlen(const char *s);

int			ft_abs(int n);

#endif