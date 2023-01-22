/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khel <ael-khel@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 18:33:01 by ael-khel          #+#    #+#             */
/*   Updated: 2023/01/22 04:48:46 by ael-khel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexlen(unsigned long n, t_printf *tab)
{
	int	hexlen;

	hexlen = n == 0;
	if (tab->hash && (tab->spec != 'p') && n)
		hexlen += 2;
	while (n)
	{
		++hexlen;
		n /= 16;
	}
	return (hexlen);
}

char	*ft_hextoa(unsigned long n, t_printf *tab)
{
	char	*str;
	char	*hex;
	int		hexlen;

	hexlen = ft_hexlen(n, tab);
	hex = "0123456789abcdef";
	if (tab->spec == 'X')
		hex = "0123456789ABCDEF";
	str = malloc(hexlen + 1);
	if (tab->hash && (tab->spec != 'p') && n)
	{
		str[0] = '0';
		str[1] = tab->spec;
	}
	else if (n == 0)
		str[0] = '0';
	str[hexlen--] = '\0';
	while (n)
	{
		str[hexlen--] = hex[n % 16];
		n /= 16;
	}
	return (str);
}

void	ft_print_ptr(unsigned long n, t_printf *tab)
{
	char	*hex;
	int		len;

	hex = ft_hextoa(n, tab);
	len = ft_hexlen(n, tab) + 2;
	if (tab->width > len)
		tab->width -= len;
	else
		tab->width = 0;
	if (!tab->minus)
		ft_putchar(' ', tab->width, tab);
	ft_putstr("0x", 2, tab);
	ft_putstr(hex, ft_strlen(hex), tab);
	if (tab->minus)
		ft_putchar(' ', tab->width, tab);
	free(hex);
}

void	ft_print_hex(unsigned int n, t_printf *tab)
{
	char	*hex;
	int		len;

	hex = ft_hextoa(n, tab);
	len = ft_hexlen(n, tab);
	if (n == 0)
	{
		tab->hash = 0;
		if (tab->dot)
			len = 0;
	}
	if (tab->minus || tab->dot)
		tab->zero = 0;
	if (tab->prc > len - tab->hash)
		tab->prc -= (len - tab->hash);
	else
		tab->prc = 0;
	if (tab->width > len + tab->prc)
		tab->width -= (len + tab->prc);
	else
		tab->width = 0;
	ft_check_hex(hex, len, tab);
	free(hex);
}

void	ft_check_hex(char	*hex, int len, t_printf *tab)
{
	if (tab->minus)
	{
		ft_putstr(hex, tab->hash, tab);
		ft_putchar('0', tab->prc, tab);
		ft_putstr(hex + tab->hash, (len - tab->hash), tab);
		ft_putchar(' ', tab->width, tab);
	}
	if (!tab->minus)
	{
		if (!tab->zero)
			ft_putchar(' ', tab->width, tab);
		ft_putstr(hex, tab->hash, tab);
		if (tab->zero)
			ft_putchar('0', tab->width, tab);
		ft_putchar('0', tab->prc, tab);
		ft_putstr(hex + tab->hash, (len - tab->hash), tab);
	}
}
