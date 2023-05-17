/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edogarci <edogarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 13:42:41 by edogarci          #+#    #+#             */
/*   Updated: 2023/05/17 15:18:27 by edogarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stddef.h>
# include <stdarg.h>
# include <unistd.h>
# include "libft/libft.h"

# define BOOL_FALSE ' '
# define BOOL_TRUE 'X'

typedef struct s_funcptr
{
	char	*(*ptr)(char *, int *len);
}	t_func_pointer;

///// MANDATORY PART /////
int			ft_printf(char const *str, ...);

#endif