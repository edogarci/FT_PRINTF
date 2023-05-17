/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edogarci <edogarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 13:54:15 by edogarci          #+#    #+#             */
/*   Updated: 2023/05/17 13:12:12 by edogarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static void	ft_read_char_from_str(char const *str, int *letra, int *is_conv)
{
	*letra = str[0];
	if (*letra == '%')
		*is_conv = BOOL_TRUE;
	else
		*is_conv = BOOL_FALSE;
}

static void	ft_printchar(int letra, int *len)
{
	printf("%c", letra);
	len++;
}

static void	ft_func_type_c(char *str, int *len)
{
	printf("Func Type C\n");
}

static void	ft_func_type_s(char *str, int *len)
{
	printf("%s", str);
}

static void	ft_func_type_p(char *str, int *len)
{
	printf("Func Type P\n");
}

static void	ft_func_type_d(char *str, int *len)
{
	printf("Func Type D\n");
}

static void	ft_func_type_i(char *str, int *len)
{
	printf("Func Type i\n");
}

static void	ft_func_type_u(char *str, int *len)
{
	printf("Func Type U\n");
}

static void	ft_func_type_x(char *str, int *len)
{
	printf("Func Type x\n");
}

static void	ft_func_type_x_uppercase(char *str, int *len)
{
	printf("Func Type X (uppercase)\n");
}

static void	ft_func_type_percentage(char *str, int *len)
{
	printf("Func Type %%\n");
}

static t_func_pointer	*ft_get_conv_func(char const *str)
{
	int				conv_type;
	t_func_pointer	*ptr_func;

	conv_type = (int)(str[0]);
	if (conv_type == 'c')
		ptr_func->ptr = &ft_func_type_c;
	else if (conv_type == 's')
		ptr_func->ptr = &ft_func_type_s;
	else if (conv_type == 'p')
		ptr_func->ptr = &ft_func_type_p;
	else if (conv_type == 'd')
		ptr_func->ptr = &ft_func_type_d;
	else if (conv_type == 'i')
		ptr_func->ptr = &ft_func_type_i;
	else if (conv_type == 'u')
		ptr_func->ptr = &ft_func_type_u;
	else if (conv_type == 'x')
		ptr_func->ptr = &ft_func_type_x;
	else if (conv_type == 'X')
		ptr_func->ptr = &ft_func_type_x_uppercase;
	else if (conv_type == '%')
		ptr_func->ptr = &ft_func_type_percentage;
	return (ptr_func);
}

static void	ft_print_conversion_value(t_func_pointer *func_ptr, char *arg)
{
}

static int	conv_counter(char *str)
{
	int	cont;
	int	pos;

	pos = 0;
	cont = 0;
	while (str[pos] != '\0')
	{
		if (str[pos] == '%')
			cont++;
		pos++;
	}
	return (cont);
}

int	ft_printf(char const *str, ...)
{
	int				letra;
	int				is_conv;
	t_func_pointer	*func_ptr;
	va_list			args;
	int				len;

	if (!str)
		return (0);
	len = 0;
	va_start(args, conv_counter(str));
	while (str[0] != '\0')
	{
		ft_read_char_from_str(str, &letra, &is_conv);
		if (is_conv == BOOL_FALSE)
			ft_printchar(letra, &len);
		else if (is_conv == BOOL_TRUE)
		{
			str++;
			func_ptr = ft_get_conv_func(str);
			(func_ptr->ptr)(va_arg(args, char *), &len);
		}
		str++;
	}
	va_end(args);
	return (len);
}

int	main(void)
{
	ft_printf("str1-%s - %s", "hola2", "test3");
	return (0);
}
