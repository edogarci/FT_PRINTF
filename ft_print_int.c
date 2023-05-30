/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edogarci <edogarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 11:07:53 by edogarci          #+#    #+#             */
/*   Updated: 2023/05/30 10:50:46 by edogarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/// @brief Prints integers on screen. It can handle negative values.
/// @param num Number to be printed.
/// @param len Total length (increased after printing).
void	ft_print_int(int num, size_t *len)
{
	if (num == -2147483648)
	{
		ft_print_str("-2147483648", len);
	}
	else if (num < 0)
	{
		ft_print_char('-', len);
		ft_print_int(num * -1, len);
	}
	else
	{
		if (num > 9)
			ft_print_int((num / 10), len);
		ft_print_int(('0' + (num % 10)), len);
	}
}
