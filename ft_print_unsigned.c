/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edogarci <edogarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 11:29:12 by edogarci          #+#    #+#             */
/*   Updated: 2023/05/24 11:55:28 by edogarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_unsigned(unsigned int num, size_t *len)
{
	char	*str;

	str = ft_convert_to_base(num, DEC_BASE);
	ft_print_str(str, len);
	free(str);
}
