/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edogarci <edogarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 10:46:11 by edogarci          #+#    #+#             */
/*   Updated: 2023/05/30 10:51:31 by edogarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	int len;

	len = ft_printf(" %p %p ", 0, 0);
	printf("%i\n", len);
	len = printf(" %p %p ", 0, 0);
	printf("%i\n", len);
	return (0);
}
