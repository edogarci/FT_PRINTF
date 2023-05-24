/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_to_base.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edogarci <edogarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 10:11:10 by edogarci          #+#    #+#             */
/*   Updated: 2023/05/24 11:53:38 by edogarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_str_len(char *str)
{
	size_t	pos;

	pos = 0;
	while (str[pos] != '\0')
		pos++;
	return (pos);
}

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

char	*ft_convert_to_base(unsigned long long n, char *base)
{
	int		n_len;
	int		base_len;
	size_t	digit;
	char	*str;

	n_len = ft_num_len(n, base);
	base_len = ft_str_len(base);
	str = malloc((n_len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (n_len > 0)
	{
		digit = n % base_len;
		str[n_len] = base[digit];
		n_len--;
	}
	return (str);
}
