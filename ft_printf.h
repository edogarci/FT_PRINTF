/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edogarci <edogarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 13:42:41 by edogarci          #+#    #+#             */
/*   Updated: 2023/05/23 14:14:01 by edogarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stddef.h>
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

# define BOOL_FALSE ' '
# define BOOL_TRUE 'X'
# define NEG_VAL '-'

///// MANDATORY PART /////
int		ft_printf(char const *str, ...);
void	ft_func_type_c(va_list args, int *len);
void	ft_func_type_p(va_list args, int *len);
void	ft_func_type_d(va_list args, int *len);
void	ft_func_type_u(va_list args, int *len);
void	ft_func_type_s(va_list args, int *len);
void	ft_func_type_percentage(int *len);
void	ft_call_conv_func(char const *str, va_list args, int *len);
char	translate_to_char(int digit);
int		get_unsigned_len(unsigned int n);
void	ft_printchar(int letra, int *len);
void	ft_assign_p(unsigned long *ul, int *resto, int *str, int *len);
int		ft_print_long_min(long long int *ul, int *len);
void	ft_x_checks(long long int *ul, int *len, int *ptr_len, char *flag);
void	ft_func_type_x(va_list args, int *len, char format);
void	ft_assign_x(char format, int *str, int *ptr_len, int resto);
void	ft_x_print_free(char flag, int *str, int ptr_len, int *len);
int		ft_get_hex_len(long long int n);
int		ft_get_ptr_len(void *ptr);
void	iterate_unsigned(unsigned int n, int len, char *str);
char	*ft_itounsigned(unsigned int n);
void	ft_read_char_from_str(char const *str, int *letra, int *is_conv);
void	ft_print_str(int *str, int *len);
char	*ft_itoa(int n);

#endif