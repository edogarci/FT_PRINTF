/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edogarci <edogarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 13:42:41 by edogarci          #+#    #+#             */
/*   Updated: 2023/05/21 11:46:13 by edogarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stddef.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

# define BOOL_FALSE ' '
# define BOOL_TRUE 'X'
# define HEX_BASE_UPPER "0123456789ABCDEF"
# define HEX_BASE_LOWER "0123456789abcdef"

///// MANDATORY PART /////
int		ft_printf(char const *str, ...);

#endif