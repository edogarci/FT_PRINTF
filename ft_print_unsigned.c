/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edogarci <edogarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 11:29:12 by edogarci          #+#    #+#             */
/*   Updated: 2023/06/01 16:13:19 by edogarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/// @brief Converts unsigned numeric value to string format and print it.
/// @param num Unsigned numeric value to print.
/// @param len Total length (increased after printing).
void	ft_print_unsigned(unsigned int num, size_t *len)
{
	ft_conv_base(num, DEC_BASE, len, 'u');
}
