/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edogarci <edogarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 18:53:55 by edogarci          #+#    #+#             */
/*   Updated: 2023/06/01 17:45:22 by edogarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/// @brief Based on character after %, function determines data type
/// and pass corresponding parameter to function on charge to
/// translate that type to string format.
/// @param args Variable containing all given variables
/// passed to main function FT_PRINTF.
/// @param str Initial string to read character following %,
/// so function is able to determine data type.
/// @param len Stores total len, which is incremented every time a part of
/// the final string is printed correctly.
void	ft_call_conv_func(va_list args, char *str, size_t *len)
{
	char	c;

	c = *str;
	if (c == 'c')
		ft_print_char(va_arg(args, int), len);
	else if (c == 's')
		ft_print_str(va_arg(args, char *), len, c);
	else if (c == 'p')
		ft_print_ptr(va_arg(args, void *), len);
	else if (c == 'i')
		ft_print_int(va_arg(args, int), len);
	else if (c == 'd')
		ft_print_int(va_arg(args, int), len);
	else if (c == 'u')
		ft_print_unsigned(va_arg(args, unsigned int), len);
	else if (c == 'x')
		ft_print_hex(va_arg(args, unsigned int), len, HEX_BASE_LOWER);
	else if (c == 'X')
		ft_print_hex(va_arg(args, unsigned int), len, HEX_BASE_UPPER);
	else if (c == '%')
		ft_print_char('%', len);
}

/// @brief Function able to print on screen various types of data:
/// - Char (%c)
/// - String (%s)
/// - Pointer (%p) (void pointer is required)
/// - Integer (%i)
/// - Decimal (%d)
/// - Unsigned (%u)
/// - Hexadecimal (lowercase %x, uppercase %X)
/// - '%' character (%%)
///
/// It works similar to standard PRINTF function.
/// 
/// Code iterates over given string (str param) looking for % character.
/// When finding one, it checks indicated type after % symbol, and translates
/// given value for that conversion (... params) to string format.
///
/// @example ft_printf("Given values are: %i and %X", int_var, hex_var);
/// @param str String that contains literal and conversions to fill
/// (%c, %s, etc.).
/// @param ... N parameters needed to fill all % in STR parameter.
/// @return Length of printed string (int type).
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
		{
			str++;
			ft_call_conv_func(args, (char *)str, &len);
		}
		else
			ft_print_char(str[0], &len);
		str++;
	}
	va_end(args);
	return (len);
}
