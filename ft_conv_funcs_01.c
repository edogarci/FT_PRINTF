/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_funcs_01.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edogarci <edogarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 16:54:00 by edogarci          #+#    #+#             */
/*   Updated: 2023/05/22 17:45:50 by edogarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "./LIBFT/libft.h"

static void	ft_printchar(int letra, int *len)
{
	write(1, &letra, 1);
	(*len)++;
}

static void	ft_func_type_c(va_list args, int *len)
{
	int	c;

	c = va_arg(args, int);
	ft_printchar(c, len);
}

static void	ft_func_type_s(va_list args, int *len)
{
	int		pos;
	char	*str;

	str = va_arg(args, char *);
	if (!str)
	{
		ft_printchar('(', len);
		ft_printchar('n', len);
		ft_printchar('u', len);
		ft_printchar('l', len);
		ft_printchar('l', len);
		ft_printchar(')', len);
	}
	else
	{
		pos = 0;
		while (str[pos] != '\0')
		{
			ft_printchar((int)str[pos], len);
			pos++;
		}	
	}
}

static void	ft_assign_p(unsigned long *ul, int resto, int *str, int *len)
{
	resto = ul % 16;
	if (resto < 10)
		*str = resto + '0';
	else
		*str = (resto - 10) + 'a';
	*ul = (*ul) / 16;
	(*len)--;
}

static void	ft_func_type_p(va_list args, int *len)
{
	void			*ptr;
	int				ptr_len;
	int				*str;
	unsigned long	ul;
	int				resto;

	ptr = va_arg(args, void *);
	ptr_len = ft_get_ptr_len(ptr);
	str = (int *)malloc((ptr_len + 1) * sizeof(char));
	if (str)
	{
		str[--ptr_len] = '\0';
		if (!ptr)
			str[--ptr_len] = '0';
		ul = (unsigned long)ptr;
		while (ul != 0)
			ft_assign_p(&ul, resto, &(str[ptr_len]), &ptr_len);
		str[--ptr_len] = 'x';
		str[ptr_len] = '0';
		ft_print_str(str, len);
		free(str);
	}
}
