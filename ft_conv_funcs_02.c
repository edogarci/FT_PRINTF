/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_funcs_02.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edogarci <edogarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 16:54:00 by edogarci          #+#    #+#             */
/*   Updated: 2023/05/23 14:03:02 by edogarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_func_type_d(va_list args, int *len)
{
	int		num;
	int		pos;
	char	*str;

	num = va_arg(args, int);
	str = ft_itoa(num);
	pos = 0;
	while (str[pos] != '\0')
	{
		ft_printchar((int)str[pos], len);
		pos++;
	}
	free(str);
}

void	ft_func_type_u(va_list args, int *len)
{
	unsigned int	num;
	int				pos;
	char			*str;

	num = va_arg(args, unsigned int);
	str = ft_itounsigned(num);
	pos = 0;
	while (str[pos] != '\0')
	{
		ft_printchar((int)str[pos], len);
		pos++;
	}
	free(str);
}

int	ft_print_long_min(long long int *ul, int *len)
{
	long long int	min_value;

	min_value = -9223372036854775807;
	if (*ul == min_value)
	{
		ft_printchar('-', len);
		ft_printchar('8', len);
		ft_printchar('0', len);
		ft_printchar('0', len);
		ft_printchar('0', len);
		ft_printchar('0', len);
		ft_printchar('0', len);
		ft_printchar('0', len);
		ft_printchar('0', len);
		ft_printchar('0', len);
		ft_printchar('0', len);
		ft_printchar('0', len);
		ft_printchar('0', len);
		ft_printchar('0', len);
		ft_printchar('0', len);
		ft_printchar('0', len);
		ft_printchar('0', len);
		return (1);
	}
	return (0);
}

void	ft_x_checks(long long int *ul, int *len, int *ptr_len, char *flag)
{
	if (*ul < 0)
	{
		*ul = *ul * -1;
		ft_printchar(NEG_VAL, len);
	}
	if (ft_get_hex_len(*ul) == 0)
	{
		*ptr_len = 1;
		*flag = BOOL_TRUE;
	}
	else
	{
		*ptr_len = ft_get_hex_len(*ul);
		*flag = BOOL_FALSE;
	}
}

void	ft_func_type_x(va_list args, int *len, char format)
{	
	int				ptr_len;
	int				*str;
	long long int	ul;
	int				resto;
	char			flag_zero;

	ul = va_arg(args, long long int);
	if (ft_print_long_min(&ul, len) == 0)
	{
		ft_x_checks(&ul, len, &ptr_len, &flag_zero);
		str = (int *)malloc((ptr_len + 1) * sizeof(char));
		if (str)
		{
			str[--ptr_len] = '\0';
			while (ul != 0)
			{
				resto = ul % 16;
				ft_assign_x(format, str, &ptr_len, resto);
				ul = ul / 16;
			}
			ft_x_print_free(flag_zero, str, ptr_len, len);
		}
	}
}
