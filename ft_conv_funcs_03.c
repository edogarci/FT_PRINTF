/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_funcs_03.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edogarci <edogarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 11:14:46 by edogarci          #+#    #+#             */
/*   Updated: 2023/05/23 14:03:04 by edogarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_assign_x(char format, int *str, int *ptr_len, int resto)
{				
	if (resto < 10)
		str[--(*ptr_len)] = resto + '0';
	else
	{
		if (format == 'x')
			str[--(*ptr_len)] = (resto - 10) + 'a';
		else if (format == 'X')
			str[--(*ptr_len)] = (resto - 10) + 'A';
	}
}

void	ft_x_print_free(char flag, int *str, int ptr_len, int *len)
{
	if (flag == BOOL_TRUE)
		str[ptr_len] = '0';
	ft_print_str(str, len);
	free(str);
}

void	ft_func_type_percentage(int *len)
{
	int	c;

	c = '%';
	write(1, &c, 1);
	(*len)++;
}

/* int ft_get_hex_len(unsigned long n) */
int	ft_get_hex_len(long long int n)
{
	int				hex_len;

	hex_len = 0;
	while (n != 0)
	{
		hex_len++;
		n = n / 16;
	}
	return (hex_len);
}

int	ft_get_ptr_len(void *ptr)
{
	unsigned long	ul;
	int				ptr_len;

	ul = (unsigned long)ptr;
	ptr_len = 0;
	while (ul > 0)
	{
		ul = ul / 16;
		ptr_len++;
	}
	ptr_len = ptr_len + 2;
	if (ptr_len < 3)
		ptr_len = 3;
	return (ptr_len);
}
