/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edogarci <edogarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 13:42:41 by edogarci          #+#    #+#             */
/*   Updated: 2023/05/30 12:45:13 by edogarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stddef.h>
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

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
size_t	ft_str_len(char *str);

#endif