/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_funcs_04.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edogarci <edogarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 11:29:37 by edogarci          #+#    #+#             */
/*   Updated: 2023/05/23 14:03:06 by edogarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	iterate_unsigned(unsigned int n, int len, char *str)
{
	char	ascii_num;

	str[len] = '\0';
	len--;
	while (len >= 0)
	{
		ascii_num = translate_to_char(n % 10);
		str[len] = ascii_num;
		n = n / 10;
		len--;
	}
}

char	*ft_itounsigned(unsigned int n)
{
	char	*ptr_ret;
	int		len;

	len = get_unsigned_len(n);
	ptr_ret = malloc((len + 1) * sizeof(char));
	if (!ptr_ret)
		return (NULL);
	iterate_unsigned(n, len, ptr_ret);
	return (ptr_ret);
}

void	ft_read_char_from_str(char const *str, int *letra, int *is_conv)
{
	*letra = str[0];
	if (*letra == '%')
		*is_conv = BOOL_TRUE;
	else
		*is_conv = BOOL_FALSE;
}

void	ft_print_str(int *str, int *len)
{
	int	pos;
	int	letra;

	pos = 0;
	while (str[pos] != '\0')
	{
		letra = str[pos];
		ft_printchar(letra, len);
		pos++;
	}
}
