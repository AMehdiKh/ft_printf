/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khel <ael-khel@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 16:47:09 by ael-khel          #+#    #+#             */
/*   Updated: 2023/01/25 10:24:37 by ael-khel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_strchr(const char *s, int c)
{
	if (!s)
		return (0);
	while (*s)
		if (*s++ == (char)c)
			return (1);
	return (0);
}

void	ft_init_tab(t_printf *tab)
{
	tab->width = 0;
	tab->space = 0;
	tab->minus = 0;
	tab->zero = 0;
	tab->hash = 0;
	tab->plus = 0;
	tab->spec = 0;
	tab->dot = 0;
	tab->prc = 0;
}

const char	*ft_check_spec(const char *format, t_printf *tab)
{
	tab->spec = *format;
	if (*format == '%')
		ft_print_char('%', tab);
	else if (*format == 'c')
		ft_print_char(va_arg(tab->ap, int), tab);
	else if (*format == 's')
		ft_print_str(va_arg(tab->ap, char *), tab);
	else if (*format == 'p')
		ft_print_ptr(va_arg(tab->ap, unsigned long), tab);
	else if (*format == 'x' || *format == 'X')
		ft_print_hex(va_arg(tab->ap, unsigned int), tab);
	else if (*format == 'd' || *format == 'i')
		ft_print_nbr(va_arg(tab->ap, int), tab);
	else if (*format == 'u')
		ft_print_nbr(va_arg(tab->ap, unsigned int), tab);
	++format;
	return (format);
}

const char	*ft_check_flag(const char *format, t_printf *tab)
{
	ft_init_tab(tab);
	while (!ft_strchr("Xxpdscui%", *format) && *format)
	{
		if (*format == ' ')
			tab->space = 1;
		else if (*format == '-')
			tab->minus = 1;
		else if (*format == '+')
			tab->plus = 1;
		else if (*format == '#')
			tab->hash = 2;
		else if (*format == '.')
			tab->dot = 1;
		else if (*format == '0' && !tab->width && !tab->dot)
			tab->zero = 1;
		else if (ft_isdigit(*format) && tab->dot)
			tab->prc = (tab->prc * 10) + (*format - 48);
		else if (ft_isdigit(*format) && !tab->dot)
			tab->width = (tab->width * 10) + (*format - 48);
		++format;
	}
	return (ft_check_spec(format, tab));
}

int	ft_printf(const char *format, ...)
{
	t_printf	tab[1];

	tab->len = 0;
	va_start(tab->ap, format);
	while (*format)
	{
		if (*format == '%')
			format = ft_check_flag(format + 1, tab);
		else
			tab->len += write(1, format++, 1);
	}
	va_end(tab->ap);
	return (tab->len);
}
