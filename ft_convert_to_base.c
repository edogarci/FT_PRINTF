/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_to_base.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edogarci <edogarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 10:11:10 by edogarci          #+#    #+#             */
/*   Updated: 2023/06/01 17:44:23 by edogarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/// @brief Returns given string length.
/// @param str String to get length from.
/// @return Length of string.
size_t	ft_str_len(char *str)
{
	size_t	pos;

	pos = 0;
	while (str[pos] != '\0')
		pos++;
	return (pos);
}

/// @brief Returns given number length based on given base values.
/// @param n Number to process.
/// @param base Base used to get number length.
/// @return Length of given number.
static size_t	ft_num_len(unsigned long long n, char *base)
{
	size_t				len;
	unsigned long long	base_len;

	len = 1;
	base_len = ft_str_len(base);
	while (n != 0)
	{
		n = n / base_len;
		len++;
	}
	return (len);
}

/// @brief Set string to null or 0
/// @param str String to set
static void	ft_set_str_null(char *str)
{
	if (str)
	{
		str[0] = '0';
		str[1] = '\0';
	}
	else
		str = NULL;
}

/// @brief Ends string with null character '\0'
/// @param n_len Last position in string
/// @param str String
static void	ft_init_str_value(int *n_len, char *str)
{
	if (!str)
	{
		str = NULL;
	}
	else
	{
		str[*n_len] = '\0';
		(*n_len)--;
	}
}

/// @brief Converts given number to string format using given base.
/// @param n Number to be transformed to string format.
/// @param base Base used to convert given number (lowercase HEX |
/// uppercase HEX | decimal)
/// @return Given number in string format.
void	ft_conv_base(unsigned long long n, char *base, size_t *len, char type)
{
	int		n_len;
	int		base_len;
	size_t	digit;
	char	*str;

	base_len = ft_str_len(base);
	n_len = ft_num_len(n, base) - 1;
	if (n_len <= 0)
	{
		str = malloc((2) * sizeof(char));
		ft_set_str_null(str);
	}
	else
	{
		str = malloc((n_len + 1) * sizeof(char));
		ft_init_str_value(&n_len, str);
		while (n_len >= 0)
		{
			digit = n % base_len;
			n = n / base_len;
			str[n_len--] = base[digit];
		}
	}
	ft_print_str(str, len, type);
	free(str);
}
