/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edogarci <edogarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 11:33:06 by edogarci          #+#    #+#             */
/*   Updated: 2023/05/24 11:46:14 by edogarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/// @brief Converts hexadecimal value (lowercase or uppercase)
/// to string format and print it.
/// @param num Hexadecimal value to be printed.
/// @param len Total length (increased after printing).
/// @param base Base to be used:
/// HEX_BASE_LOWER = '0123456789abcdef' or
/// HEX_BASE_UPPER = '0123456789ABCDEF'
void	ft_print_hex(unsigned int num, size_t *len, char *base)
{
	char	*str;

	str = ft_convert_to_base(num, base);
	ft_print_str(str, len);
	free(str);
}
