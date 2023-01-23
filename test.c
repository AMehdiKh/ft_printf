/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khel <ael-khel@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 19:02:40 by ael-khel          #+#    #+#             */
/*   Updated: 2023/01/23 05:24:22 by ael-khel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <limits.h>
#include "Bonus/ft_printf_bonus.h"

int	main(void)
{
	int	a;

	printf("|");
	a = printf("printf :%.x", (unsigned int)-1);
	printf("|	%d\n", a);
	/////////////////////////////////////
	ft_printf("|");
	a = ft_printf("printf :%.203x", (unsigned int)-1);
	ft_printf("|	%d\n", a);
	return (0);
}
