/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khel <ael-khel@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 02:40:56 by ael-khel          #+#    #+#             */
/*   Updated: 2023/01/22 14:26:52 by ael-khel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strlen(const char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		++i;
	return (i);
}

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
	if (!tab->dot || (tab->prc > ft_strlen(s)))
		tab->prc = ft_strlen(s);
	if (!tab->minus && ((tab->width - tab->prc) > 0))
		ft_putchar(' ', tab->width - tab->prc, tab);
	ft_putstr(s, tab->prc, tab);
	if (tab->minus && ((tab->width - tab->prc) > 0))
		ft_putchar(' ', tab->width - tab->prc, tab);
}
