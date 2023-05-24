/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edogarci <edogarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 19:01:52 by edogarci          #+#    #+#             */
/*   Updated: 2023/05/24 11:45:06 by edogarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/// @brief Printf single character on screen.
/// @param c Single character to be printed.
/// @param len Total length (increased after printing).
void	ft_print_char(char c, size_t *len)
{
	write(1, &c, 1);
	(*len)++;
}
