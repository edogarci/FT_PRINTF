/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edogarci <edogarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 10:01:53 by edogarci          #+#    #+#             */
/*   Updated: 2023/06/01 16:13:07 by edogarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/// @brief Converts pointer (void * required) to string and print it.
/// @param ptr Pointer address to be printed.
/// @param len Total length (increased after printing).
void	ft_print_ptr(void *ptr, size_t *len)
{
	unsigned long long	ptr_addrs;

	if (ptr == NULL)
		ptr_addrs = 0;
	else
		ptr_addrs = (unsigned long long)ptr;
	ft_conv_base(ptr_addrs, HEX_BASE_LOWER, len, 'p');
}
