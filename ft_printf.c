/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edogarci <edogarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 13:54:15 by edogarci          #+#    #+#             */
/*   Updated: 2023/05/22 17:49:08 by edogarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "./LIBFT/libft.h"

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

	cont = 1;
	while (n / 10 != 0)
	{
		n = n / 10;
		cont++;
	}
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

//////////////////////////////////////////////////
static void	ft_read_char_from_str(char const *str, int *letra, int *is_conv)
{
	*letra = str[0];
	if (*letra == '%')
		*is_conv = BOOL_TRUE;
	else
		*is_conv = BOOL_FALSE;
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

static int ft_get_ptr_len(void *ptr)
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

/* static int ft_get_hex_len(unsigned long n) */
static int ft_get_hex_len(long long int n)
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

static void	ft_func_type_percentage(int *len)
{
	int	c;

	c = '%';
	write(1, &c, 1);
	(*len)++;
}

static void	ft_call_conv_func(char const *str, va_list args, int *len)
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
		while (str != '\0')
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
	printf("->NUMBER:       %lu <-\n", LONG_MIN);
 	ft_printf("->FT_PRINTF: %x\n", LONG_MIN + 1);
	return (0);
}
 */