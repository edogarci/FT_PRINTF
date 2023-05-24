/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edogarci <edogarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 18:53:55 by edogarci          #+#    #+#             */
/*   Updated: 2023/05/24 12:11:33 by edogarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_call_conv_func(va_list args, char *str, size_t *len)
{
	char	c;

	c = *(str++);
	if (c == TYPE_CHAR)
		ft_print_char(va_arg(args, int), len);
	else if (c == TYPE_STRING)
		ft_print_str(va_arg(args, char *), len);
	else if (c == TYPE_POINTER)
		ft_print_ptr(va_arg(args, void *), len);
	else if (c == TYPE_INTEGER)
		ft_print_int(va_arg(args, int), len);
	else if (c == TYPE_DECIMAL)
		ft_print_int(va_arg(args, int), len);
	else if (c == TYPE_UNSIGNED)
		ft_print_unsigned(va_arg(args, unsigned int), len);
	else if (c == TYPE_HEX_LOWER)
		ft_print_hex(va_arg(args, unsigned int), len, HEX_BASE_LOWER);
	else if (c == TYPE_HEX_UPPER)
		ft_print_hex(va_arg(args, unsigned int), len, HEX_BASE_UPPER);
	else if (c == TYPE_PERCENTAGE)
		ft_print_char(SIGN_PERCENTAGE, len);
}

int	ft_printf(char const *str, ...)
{
	va_list	args;
	size_t	len;

	if (!str)
		return (0);
	len = 0;
	va_start(args, str);
	while (str[0] != '\0')
	{
		if (str[0] == '%')
			ft_call_conv_func(args, (char *)str, &len);
		else
			ft_print_char(str[0], &len);
		str++;
	}
	va_end(args);
	return (len);
}
/* 
int	main(void)
{
	ft_printf("%c", '0');
	return (0);
} */