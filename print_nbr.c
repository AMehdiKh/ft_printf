/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khel <ael-khel@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 06:13:03 by ael-khel          #+#    #+#             */
/*   Updated: 2023/01/22 11:51:01 by ael-khel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_nbrlen(long n, t_printf *tab)
{
	int	nbrlen;

	nbrlen = n <= 0;
	if (n >= 0 && tab->plus && tab->spec != 'u')
		nbrlen += 1;
	while (n)
	{
		++nbrlen;
		n /= 10;
	}
	return (nbrlen);
}

char	*ft_itoa(long n, t_printf *tab)
{
	char	*str;
	int		nbrlen;

	nbrlen = ft_nbrlen(n, tab);
	str = malloc(nbrlen + 1);
	if (!str)
		return (NULL);
	if (tab->spec == 'u' || n < 0)
		tab->plus = 0;
	if (tab->plus)
		str[0] = '+';
	if (n == 0)
		str[tab->plus] = '0';
	if (n < 0)
		str[0] = '-';
	str[nbrlen--] = '\0';
	while (n)
	{
		str[nbrlen--] = (-(n < 0) * (n % 10) + (n > 0) * (n % 10)) + 48;
		n /= 10;
	}
	return (str);
}

void	ft_print_nbr(long n, t_printf *tab)
{
	char	*nbr;
	int		len;
	int		neg;

	nbr = ft_itoa(n, tab);
	len = ft_nbrlen(n, tab);
	neg = (n < 0);
	if (n == 0 && tab->dot)
		len = 0;
	if (tab->minus || tab->dot)
		tab->zero = 0;
	if (neg || tab->plus)
		tab->space = 0;
	if (tab->prc > len - neg - tab->plus)
		tab->prc -= (len - neg - tab->plus);
	else
		tab->prc = 0;
	if (tab->width > len + tab->prc + tab->space)
		tab->width -= (len + tab->prc + tab->space);
	else
		tab->width = 0;
	ft_check_nbr(nbr, len, neg, tab);
	free(nbr);
}

void	ft_check_nbr(char *nbr, int len, int neg, t_printf *tab)
{
	if (tab->minus)
	{
		ft_putchar(' ', tab->space, tab);
		ft_putstr(nbr, neg + tab->plus, tab);
		ft_putchar('0', tab->prc, tab);
		ft_putstr(nbr + (neg + tab->plus), len - (neg + tab->plus), tab);
		ft_putchar(' ', tab->width, tab);
	}
	if (!tab->minus)
	{
		ft_putchar(' ', tab->space, tab);
		if (!tab->zero)
			ft_putchar(' ', tab->width, tab);
		ft_putstr(nbr, neg + tab->plus, tab);
		if (tab->zero)
			ft_putchar('0', tab->width, tab);
		ft_putchar('0', tab->prc, tab);
		ft_putstr(nbr + (neg + tab->plus), len - (neg + tab->plus), tab);
	}
}

int	ft_abs(int n)
{
	return ((-(n < 0) * n) + (n + (n > 0)));
}
