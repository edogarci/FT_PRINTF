/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edogarci <edogarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 13:54:15 by edogarci          #+#    #+#             */
/*   Updated: 2023/05/19 13:42:02 by edogarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

static int	get_number_len(int n)
{
	int		cont;
	char	neg;

	neg = ' ';
	if (n < 0)
		neg = 'X';
	cont = 1;
	while (n / 10 != 0)
	{
		n = n / 10;
		cont++;
	}
	if (neg == 'X')
		return (cont + 1);
	else
		return (cont);
}

static int	get_unsigned_len(unsigned int n)
{
	int		cont;
/* 	char	neg;

	neg = ' ';
	if (n < (unsigned int )0)
		neg = 'X'; */
	cont = 1;
	while (n / 10 != 0)
	{
		n = n / 10;
		cont++;
	}
/* 	if (neg == 'X')
		return (cont + 1);
	else */
	return (cont);
}

static char	translate_to_char(int digit)
{
	char	ascii;

	if (digit < 0)
		digit = digit * -1;
	ascii = digit + '0';
	return (ascii);
}

static void	iterate_number(int n, int len, char *str)
{
	char	ascii_num;
	char	neg_flag;

	neg_flag = ' ';
	if (n < 0)
		neg_flag = 'X';
	str[len] = '\0';
	len--;
	while ((neg_flag == ' ' && len >= 0)
		|| (neg_flag == 'X' && len > 0))
	{
		ascii_num = translate_to_char(n % 10);
		str[len] = ascii_num;
		n = n / 10;
		len--;
	}
	if (neg_flag == 'X')
		str[len] = '-';
}

static void	iterate_unsigned(unsigned int n, int len, char *str)
{
	char	ascii_num;
/* 	char	neg_flag;

	neg_flag = ' ';
	if (n < 0)
		neg_flag = 'X'; */
	str[len] = '\0';
	len--;
	while (len >= 0)
	{
		ascii_num = translate_to_char(n % 10);
		str[len] = ascii_num;
		n = n / 10;
		len--;
	}
/* 	if (neg_flag == 'X')
		str[len] = '-'; */
}

char	*ft_itoa(int n)
{
	char	*ptr_ret;
	int		len;

	len = get_number_len(n);
	ptr_ret = malloc((len + 1) * sizeof(char));
	if (!ptr_ret)
		return (NULL);
	iterate_number(n, len, ptr_ret);
	return (ptr_ret);
}

char	*ft_itounsigned(unsigned int n)
{
	char	*ptr_ret;
	int		len;

	len = get_unsigned_len(n);
	ptr_ret = malloc((len + 1) * sizeof(char));
	if (!ptr_ret)
		return (NULL);
	iterate_unsigned(n, len, ptr_ret);
	return (ptr_ret);
}
/* 
char	*ft_ftoa(float n)
{
	char	*ptr_ret;
	int		len;

	len = get_number_len(n);
	ptr_ret = malloc((len + 1) * sizeof(char));
	if (!ptr_ret)
		return (NULL);
	iterate_number(n, len, ptr_ret);
	return (ptr_ret);
} */

//////////////////////////////////////////////////
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
	write(1, &letra, 1);
	(*len)++;
}

static void	ft_print_str(int *str, int *len)
{
	int	pos;
	int	letra;

	pos = 0;
	while (str[pos] != '\0')
	{
		letra = str[pos];
		ft_printchar(letra, len);
		pos++;
	}
}

static void	ft_func_type_c(va_list args, int *len)
{
	char	*c;

	c = va_arg(args, char *);
	ft_printchar((int)(c[0]), len);
}

static void	ft_func_type_s(va_list args, int *len)
{
	int		pos;
	char	*str;

	str = va_arg(args, char *);
	pos = 0;
	while (str[pos] != '\0')
	{
		ft_printchar((int)str[pos], len);
		pos++;
	}
}

static int ft_get_hex_ptr_len(void *ptr)
{
	unsigned long	ul;
	int				ptr_len;
	
	ul = (unsigned long)ptr;
	ptr_len = 0;
	while (ul > 0)
	{
		ul = ul / 16;
		ptr_len++;
	}
	return (ptr_len);
}

static int ft_get_hex_len(unsigned long n)
{
	int				hex_len;
	
	hex_len = 0;
	while (n > 0)
	{
		n = n / 16;
		hex_len++;
	}
	return (hex_len);
}

static void	ft_func_type_p(va_list args, int *len)
{
	void			*ptr;
	int				ptr_len;
	int				*str;
	unsigned long	ul;
	int				resto;

	ptr = va_arg(args, void *);
	ptr_len = ft_get_hex_ptr_len(ptr) + 2;
	str = (int *)malloc((ptr_len + 1) * sizeof(char));
/* 	if (!str)
		return (NULL); */
	if (str)
	{
		str[ptr_len] = '\0';
		ptr_len--;
		ul = (unsigned long)ptr;
		while (ul != 0)
		{
			resto = ul % 16;
			if (resto < 10)
				str[ptr_len] = resto + '0';
			else
				str[ptr_len] = (resto - 10) + 'a';

			ul = ul / 16;
			ptr_len--;
		}
		str[ptr_len] = 'x';
		ptr_len--;
		str[ptr_len] = '0';
		ft_print_str(str, len);
		free(str);
	}
}

static void	ft_func_type_d(va_list args, int *len)
{
	int		num;
	int		pos;
	char	*str;

	num = va_arg(args, int);
	str = ft_itoa(num);

	pos = 0;
	while (str[pos] != '\0')
	{
		ft_printchar((int)str[pos], len);
		pos++;
	}
	free(str);
}
/* 
static void	ft_func_type_i(va_list args, int *len)
{
	int val;
	
	val = va_arg(args, int);
} */

static void	ft_func_type_u(va_list args, int *len)
{
	unsigned int	num;
	int				pos;
	char			*str;

	num = va_arg(args, unsigned int);
	str = ft_itounsigned(num);
	pos = 0;
	while (str[pos] != '\0')
	{
		ft_printchar((int)str[pos], len);
		pos++;
	}
	free(str);
}

static void	ft_func_type_x(va_list args, int *len)
{	
	int				ptr_len;
	int				*str;
	unsigned long	ul;
	int				resto;

	ul = va_arg(args, unsigned long);
	ptr_len = ft_get_hex_len(ul) + 2;
	str = (int *)malloc((ptr_len + 1) * sizeof(char));
	if (str)
	{
		str[ptr_len] = '\0';
		ptr_len--;
		while (ul != 0)
		{
			resto = ul % 16;
			if (resto < 10)
				str[ptr_len] = resto + '0';
			else
				str[ptr_len] = (resto - 10) + 'a';

			ul = ul / 16;
			ptr_len--;
		}
		str[ptr_len] = 'x';
		ptr_len--;
		str[ptr_len] = '0';
		ft_print_str(str, len);
		free(str);
	}
}

static void	ft_func_type_x_uppercase(va_list args, int *len)
{	
	int				ptr_len;
	int				*str;
	unsigned long	ul;
	int				resto;

	ul = va_arg(args, unsigned long);
	ptr_len = ft_get_hex_len(ul) + 2;
	str = (int *)malloc((ptr_len + 1) * sizeof(char));
	if (str)
	{
		str[ptr_len] = '\0';
		ptr_len--;
		while (ul != 0)
		{
			resto = ul % 16;
			if (resto < 10)
				str[ptr_len] = resto + '0';
			else
				str[ptr_len] = (resto - 10) + 'A';

			ul = ul / 16;
			ptr_len--;
		}
		str[ptr_len] = 'x';
		ptr_len--;
		str[ptr_len] = '0';
		ft_print_str(str, len);
		free(str);
	}
}

static void	ft_func_type_percentage(int *len)
{
	int	c;

	c = '%';
	write(1, &c, 1);
	(*len)++;
}

static void	ft_call_conv_func(char *str, va_list args, int *len)
{
	int				conv_type;

	conv_type = (int)(str[0]);
	if (conv_type == 'c')
		ft_func_type_c(args, len);
	else if (conv_type == 's')
		ft_func_type_s(args, len);
	else if (conv_type == 'p')
		ft_func_type_p(args, len);
	else if (conv_type == 'd')
		ft_func_type_d(args, len);
	else if (conv_type == 'i')
/* 		ft_func_type_i(args, len); */
		ft_func_type_d(args, len);
	else if (conv_type == 'u')
		ft_func_type_u(args, len);
	else if (conv_type == 'x')
		ft_func_type_x(args, len);
	else if (conv_type == 'X')
		ft_func_type_x_uppercase(args, len);
	else if (conv_type == '%')
		ft_func_type_percentage(len);
}

/* static int	conv_counter(char *str)
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
}*/

int	ft_printf(char const *str, ...)
{
	int				letra;
	int				is_conv;
	va_list			args;
	int				len;

	if (!str)
		return (0);
	len = 0;
	va_start(args, str);
	while (str[0] != '\0')
	{
		ft_read_char_from_str(str, &letra, &is_conv);
		if (is_conv == BOOL_FALSE)
			ft_printchar(letra, &len);
		else if (is_conv == BOOL_TRUE)
		{
			str++;
			ft_call_conv_func((char *)str, args, &len);
		}
		str++;
	}
	va_end(args);
	return (len);
}
/* 
int	main(void)
{
	char c;
	char	str[] = "test";
	float	f;
	unsigned int un_int = 95;
	int	*p;
	int d;
	
	d = 0567;
 	ft_printf("Type U: %d\n", d);

	return (0);
}
*/