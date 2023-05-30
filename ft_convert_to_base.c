/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_to_base.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edogarci <edogarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 10:11:10 by edogarci          #+#    #+#             */
/*   Updated: 2023/05/30 12:45:51 by edogarci         ###   ########.fr       */
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

/// @brief Converts given number to string format using given base.
/// @param n Number to be transformed to string format.
/// @param base Base used to convert given number (lowercase HEX |
/// uppercase HEX | decimal)
/// @return Given number in string format.
char	*ft_convert_to_base(unsigned long long n, char *base)
{
	int		n_len;
	int		base_len;
	size_t	digit;
	char	*str;

	base_len = ft_str_len(base);
	n_len = ft_num_len(n, base) - 1;
	if (n_len <= 0)
	{
		n_len = 0;
		str = malloc((2) * sizeof(char));
		str[0] = '0';
		str[1] = '\0';
	}
	else
	{
		str = malloc((n_len + 1) * sizeof(char));
		if (!str)
			return (NULL);
		str[n_len] = '\0';
		n_len--;
		while (n_len >= 0)
		{
			digit = n % base_len;
			n = n / base_len;
			str[n_len] = base[digit];
			n_len--;
		}
	}
	return (str);
}
