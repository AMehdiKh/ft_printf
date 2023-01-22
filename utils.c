/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khel <ael-khel@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 02:40:56 by ael-khel          #+#    #+#             */
/*   Updated: 2023/01/21 23:15:35 by ael-khel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c, int len, t_printf *tab)
{
	while (len--)
		tab->len += write(1, &c, 1);
}

void	ft_putstr(char *s, int len, t_printf *tab)
{
	while (len--)
		tab->len += write(1, s++, 1);
}

void	ft_print_char(char c, t_printf *tab)
{
	tab->width += (tab->width == 0);
	if (!tab->minus)
		ft_putchar(' ', --tab->width, tab);
	ft_putchar(c, 1, tab);
	if (tab->minus)
		ft_putchar(' ', --tab->width, tab);
}

void	ft_print_str(char *s, t_printf *tab)
{
	if (!s)
		s = "(null)";
	if (!tab->dot || (tab->prc > (int)ft_strlen(s)))
		tab->prc = ft_strlen(s);
	if (!tab->minus && ((tab->width - tab->prc) > 0))
		ft_putchar(' ', tab->width - tab->prc, tab);
	ft_putstr(s, tab->prc, tab);
	if (tab->minus && ((tab->width - tab->prc) > 0))
		ft_putchar(' ', tab->width - tab->prc, tab);
}

void	ft_putnbr(long n, t_printf *tab)
{
	if (n < 0)
	{
		ft_putchar('-', 1, tab);
		n = -n;
	}
	if (n >= 10)
		ft_putnbr(n / 10, tab);
	ft_putchar((n % 10) + 48, 1, tab);
}

int	ft_abs(int n)
{
	return ((-(n < 0) * n) + (n * (n > 0)));
}
