/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khel <ael-khel@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 19:02:40 by ael-khel          #+#    #+#             */
/*   Updated: 2023/01/22 04:32:23 by ael-khel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <limits.h>
#include "ft_printf.h"

int	main(void)
{

int a;
	printf("|");
	a = printf("printf :%.0x", 0);
	printf("|%d\n", a);

/* Mo9arana bayna a7ssn printf (dyali) wa akhnaz printf (dyalhum) */

	ft_printf("|");
	a = ft_printf("printf :%.0x", 0);
	ft_printf("|%d\n", a);
	return (0);
}
