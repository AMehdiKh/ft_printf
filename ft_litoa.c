/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_litoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khel <ael-khel@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 19:06:48 by ael-khel          #+#    #+#             */
/*   Updated: 2023/01/21 18:30:37 by ael-khel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		++s;
	}
	if (!((char)c))
		return ((char *)s);
	return (NULL);
}

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i++])
		;
	return (i - 1);
}

int	ft_nbrlen(long n, int base, t_printf *tab)
{
	int	nbrlen;

	nbrlen = n <= 0;
	while (n)
	{
		++nbrlen;
		n /= base;
	}
	// if (tab->hash && (tab->spec == 'X' || tab->spec == 'x') || tab->spec == 'p')
	if (tab->spec == 'p')
		nbrlen += 2;
	return (nbrlen);
}

char	*ft_itoa_base(long n, int base, t_printf *tab)
{
	char	*ptr;
	char	*hex;
	int		nbrlen;

	nbrlen = ft_nbrlen(n, base, tab);
	hex = "0123456789abcdef";
	if (tab->spec == 'X')
		hex = "0123456789ABCDEF";
	if (tab->spec == 'p')
		nbrlen -= 2;
	ptr = malloc(nbrlen + 1);
	ptr[nbrlen] = '\0';
	--nbrlen;
	if (n == 0)
		ptr[0] = '0';
	if (n < 0)
		ptr[0] = '-';
	while (n)
	{
		ptr[nbrlen--] = hex[(-(n < 0) * (n % base)) + ((n > 0) * (n % base))];
		n /= base;
	}
	return (ptr);
}
