/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edogarci <edogarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 13:54:15 by edogarci          #+#    #+#             */
/*   Updated: 2023/05/23 14:45:39 by edogarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* 
void	ft_printchar(int letra, int *len)
{
	write(1, &letra, 1);
	(*len)++;
}

void	ft_func_type_c(va_list args, int *len)
{
	int	c;

	c = va_arg(args, int);
	ft_printchar(c, len);
}

void	ft_func_type_s(va_list args, int *len)
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

void	ft_assign_p(unsigned long *ul, int *resto, int *str, int *len)
{
	(*resto) = *ul % 16;
	if ((*resto) < 10)
		*str = (*resto) + '0';
	else
		*str = ((*resto) - 10) + 'a';
	*ul = (*ul) / 16;
	(*len)--;
}

void	ft_func_type_p(va_list args, int *len)
{
	void			*ptr;
	int				ptr_len;
	int				*str;
	unsigned long	ul;
	int				resto;

	resto = 0;
	ptr = va_arg(args, void *);
	ptr_len = ft_get_ptr_len(ptr);
	str = (int *)malloc((ptr_len + 1) * sizeof(char));
	if (str)
	{
		str[ptr_len--] = '\0';
		if (!ptr)
			str[ptr_len] = '0';
		ul = (unsigned long)ptr;
		while (ul != 0)
			ft_assign_p(&ul, &resto, &(str[ptr_len]), &ptr_len);
		str[ptr_len--] = 'x';
		str[ptr_len] = '0';
		ft_print_str(str, len);
		free(str);
	}
}

void	ft_func_type_d(va_list args, int *len)
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

void	ft_func_type_u(va_list args, int *len)
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

int	ft_print_long_min(long long int *ul, int *len)
{
	long long int	min_value;

	min_value = -9223372036854775807;
	if (*ul == min_value)
	{
		ft_printchar('-', len);
		ft_printchar('8', len);
		ft_printchar('0', len);
		ft_printchar('0', len);
		ft_printchar('0', len);
		ft_printchar('0', len);
		ft_printchar('0', len);
		ft_printchar('0', len);
		ft_printchar('0', len);
		ft_printchar('0', len);
		ft_printchar('0', len);
		ft_printchar('0', len);
		ft_printchar('0', len);
		ft_printchar('0', len);
		ft_printchar('0', len);
		ft_printchar('0', len);
		ft_printchar('0', len);
		return (1);
	}
	return (0);
}

void	ft_x_checks(long long int *ul, int *len, int *ptr_len, char *flag)
{
	if (*ul < 0)
	{
		*ul = *ul * -1;
		ft_printchar(NEG_VAL, len);
	}
	if (ft_get_hex_len(*ul) == 0)
	{
		*ptr_len = 1;
		*flag = BOOL_TRUE;
	}
	else
	{
		*ptr_len = ft_get_hex_len(*ul);
		*flag = BOOL_FALSE;
	}
}

void	ft_func_type_x(va_list args, int *len, char format)
{	
	int				ptr_len;
	int				*str;
	long long int	ul;
	int				resto;
	char			flag_zero;

	ul = va_arg(args, long long int);
	if (ft_print_long_min(&ul, len) == 0)
	{
		ft_x_checks(&ul, len, &ptr_len, &flag_zero);
		str = (int *)malloc((ptr_len + 1) * sizeof(char));
		if (str)
		{
			str[--ptr_len] = '\0';
			while (ul != 0)
			{
				resto = ul % 16;
				ft_assign_x(format, str, &ptr_len, resto);
				ul = ul / 16;
			}
			ft_x_print_free(flag_zero, str, ptr_len, len);
		}
	}
}

void	ft_assign_x(char format, int *str, int *ptr_len, int resto)
{				
	if (resto < 10)
		str[--(*ptr_len)] = resto + '0';
	else
	{
		if (format == 'x')
			str[--(*ptr_len)] = (resto - 10) + 'a';
		else if (format == 'X')
			str[--(*ptr_len)] = (resto - 10) + 'A';
	}
}

void	ft_x_print_free(char flag, int *str, int ptr_len, int *len)
{
	if (flag == BOOL_TRUE)
		str[ptr_len] = '0';
	ft_print_str(str, len);
	free(str);
}

void	ft_func_type_percentage(int *len)
{
	int	c;

	c = '%';
	write(1, &c, 1);
	(*len)++;
}

int	ft_get_hex_len(long long int n)
{
	int				hex_len;

	hex_len = 0;
	while (n != 0)
	{
		hex_len++;
		n = n / 16;
	}
	return (hex_len);
}

int	ft_get_ptr_len(void *ptr)
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
	ptr_len = ptr_len + 2;
	if (ptr_len < 3)
		ptr_len = 3;
	return (ptr_len);
}

void	iterate_unsigned(unsigned int n, int len, char *str)
{
	char	ascii_num;

	str[len] = '\0';
	len--;
	while (len >= 0)
	{
		ascii_num = translate_to_char(n % 10);
		str[len] = ascii_num;
		n = n / 10;
		len--;
	}
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

void	ft_read_char_from_str(char const *str, int *letra, int *is_conv)
{
	*letra = str[0];
	if (*letra == '%')
		*is_conv = BOOL_TRUE;
	else
		*is_conv = BOOL_FALSE;
}

void	ft_print_str(int *str, int *len)
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

char	translate_to_char(int digit)
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
 */
///////////////////////////////

int	get_unsigned_len(unsigned int n)
{
	int		cont;

	cont = 1;
	while (n / 10 != 0)
	{
		n = n / 10;
		cont++;
	}
	return (cont);
}

void	ft_call_conv_func(char const *str, va_list args, int *len)
{
	int	conv_type;

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
		ft_func_type_d(args, len);
	else if (conv_type == 'u')
		ft_func_type_u(args, len);
	else if (conv_type == 'x')
		ft_func_type_x(args, len, 'x');
	else if (conv_type == 'X')
		ft_func_type_x(args, len, 'X');
	else if (conv_type == '%')
		ft_func_type_percentage(len);
}

int	ft_printf(char const *str, ...)
{
	int				letra;
	int				is_conv;
	va_list			args;
	int				len;

	len = 0;
	if (str)
	{
		va_start(args, str);
		while (str[0] != '\0')
		{
			ft_read_char_from_str(str, &letra, &is_conv);
			if (is_conv == BOOL_FALSE)
				ft_printchar(letra, &len);
			else if (is_conv == BOOL_TRUE)
			{
				str++;
				ft_call_conv_func(str, args, &len);
			}
			str++;
		}
		va_end(args);
	}
	return (len);
}

/* int	main(void)
{
	ft_printf("TEST: %p ", -1);
	printf("\n");
}
*/