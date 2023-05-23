/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_funcs_02.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edogarci <edogarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 16:54:00 by edogarci          #+#    #+#             */
/*   Updated: 2023/05/22 17:57:17 by edogarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "./LIBFT/libft.h"

static void	ft_func_type_d(va_list args, int *len)
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

static void	ft_func_type_u(va_list args, int *len)
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

static void ft_print_long_min(int *len)
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
}
static void	ft_func_type_x(va_list args, int *len, char format)
{	
	int		ptr_len;
	int		*str;
	long long int		ul;
	int		resto;
	char	flag_zero;
	char	flag_max;

	ul = va_arg(args, long long int);
	if (ul == -9223372036854775808)
        ft_print_long_min(len);
	else
	{
		if (ul < 0)
		{
			ul = ul * -1;
			ft_printchar(NEG_VAL, len);
		}
		if (ft_get_hex_len(ul) == 0)
		{
			ptr_len = 1;
			flag_zero = BOOL_TRUE;
		}
		else
		{
			ptr_len = ft_get_hex_len(ul);
			flag_zero = BOOL_FALSE;
		}
		str = (int *)malloc((ptr_len + 1) * sizeof(char));
		if (str)
		{
			str[--ptr_len] = '\0';
			while (ul != 0)
			{
				resto = ul % 16;
				if (resto < 10)
					str[--ptr_len] = resto + '0';
				else
				{
					if (format == 'x')
						str[--ptr_len] = (resto - 10) + 'a';
					else if (format == 'X')
						str[--ptr_len] = (resto - 10) + 'A';
				}
				ul = ul / 16;
			}
			if (flag_zero == BOOL_TRUE)
				str[ptr_len] = '0';
			ft_print_str(str, len);
			free(str);
		}
	}
}