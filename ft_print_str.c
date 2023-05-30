/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edogarci <edogarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 09:54:50 by edogarci          #+#    #+#             */
/*   Updated: 2023/05/30 10:50:51 by edogarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/// @brief Print string characters one by one and increment len.
/// @param str String to be printed.
/// @param len Total length (increased after printing).
void	ft_print_str(char *str, size_t *len)
{
	int	str_len;
	int pos;

	if (!str)
		str = "(null)";
	pos = 0;
	str_len = ft_str_len(str);
	while (pos < str_len)
	{
		ft_print_char(str[pos], len);
		pos++;
	}
}
