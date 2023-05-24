/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edogarci <edogarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 13:42:41 by edogarci          #+#    #+#             */
/*   Updated: 2023/05/24 11:56:32 by edogarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stddef.h>
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

# define BOOL_FALSE ' '
# define BOOL_TRUE 'X'
# define SIGN_NEGATIVE '-'
# define SIGN_PERCENTAGE '%'
# define TYPE_CHAR 'c'
# define TYPE_STRING 's'
# define TYPE_POINTER 'p'
# define TYPE_DECIMAL 'd'
# define TYPE_INTEGER 'i'
# define TYPE_UNSIGNED 'u'
# define TYPE_HEX_LOWER 'x'
# define TYPE_HEX_UPPER 'X'
# define TYPE_PERCENTAGE '%'
# define HEX_BASE_LOWER "0123456789abcdef"
# define HEX_BASE_UPPER "0123456789ABCDEF"
# define DEC_BASE "0123456789"

int		ft_printf(char const *str, ...);
void	ft_print_char(char c, size_t *len);
void	ft_print_str(char *str, size_t *len);
void	ft_print_ptr(void *ptr, size_t *len);
char	*ft_convert_to_base(unsigned long long n, char *base);
void	ft_print_int(int num, size_t *len);
void	ft_print_unsigned(unsigned int num, size_t *len);
void	ft_print_hex(unsigned int num, size_t *len, char *base);

#endif