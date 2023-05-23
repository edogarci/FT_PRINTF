/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edogarci <edogarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 13:42:41 by edogarci          #+#    #+#             */
/*   Updated: 2023/05/22 17:48:12 by edogarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stddef.h>
# include <stdarg.h>
/* # include <unistd.h>
# include <stdlib.h>
# include <limits.h> */
#include "./LIBFT/libft.h"

# define BOOL_FALSE ' '
# define BOOL_TRUE 'X'
# define INT_MIN_VAL 'm'
# define INT_MAX_VAL 'M'
# define NEG_VAL '-'
# define HEX_BASE_UPPER "0123456789ABCDEF"
# define HEX_BASE_LOWER "0123456789abcdef"

///// MANDATORY PART /////
int		    ft_printf(char const *str, ...);

#endif