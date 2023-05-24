/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edogarci <edogarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 10:01:53 by edogarci          #+#    #+#             */
/*   Updated: 2023/05/24 15:22:48 by edogarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/// @brief Converts pointer (void * required) to string and print it.
/// @param ptr Pointer address to be printed.
/// @param len Total length (increased after printing).
void	ft_print_ptr(void *ptr, size_t *len)
{
	char				*addrs_str;
	unsigned long long	ptr_addrs;

	ptr_addrs = (unsigned long long)ptr;
	addrs_str = ft_convert_to_base(ptr_addrs, HEX_BASE_LOWER);
	ft_print_str("0x", len);
	ft_print_str(addrs_str, len);
	free(addrs_str);
}
