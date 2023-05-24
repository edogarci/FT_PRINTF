/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edogarci <edogarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 09:54:50 by edogarci          #+#    #+#             */
/*   Updated: 2023/05/24 11:48:01 by edogarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/// @brief Print string characters one by one and increment len.
/// @param str String to be printed.
/// @param len Total length (increased after printing).
void	ft_print_str(char *str, size_t *len)
{
	if (!str)
		str = "(null)";
	while (*str)
	{
		ft_print_char(*str, len);
		str++;
	}
}
