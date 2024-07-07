/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iuhara <iuhara@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 15:57:31 by iuhara            #+#    #+#             */
/*   Updated: 2024/07/06 15:38:17 by iuhara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_format(va_list arg_ptr, char specifier, int *len)
{
	static const char *const	b_dec = "0123456789";
	static const char *const	b_hx = "0123456789abcdef";
	static const char *const	b_hx_uper = "0123456789ABCDEF";

	if (specifier == 'c')
		return (ft_putchar_fd(va_arg(arg_ptr, int), 1, len));
	else if (specifier == 's')
		return (ft_putstr_fd(va_arg(arg_ptr, char *), 1, len));
	else if (specifier == 'p')
	{
		if (ft_putstr_fd("0x", 1, len) == -1)
			return (-1);
		return (ft_putnbr_fd((uintptr_t)va_arg(arg_ptr, void *), b_hx, 1, len));
	}
	else if (specifier == 'd' || specifier == 'i')
		return (ft_putnbr_signed_fd(va_arg(arg_ptr, int), b_dec, 1, len));
	else if (specifier == 'u')
		return (ft_putnbr_fd(va_arg(arg_ptr, unsigned int), b_dec, 1, len));
	else if (specifier == 'x')
		return (ft_putnbr_fd(va_arg(arg_ptr, unsigned int), b_hx, 1, len));
	else if (specifier == 'X')
		return (ft_putnbr_fd(va_arg(arg_ptr, unsigned int), b_hx_uper, 1, len));
	return (0);
}

int	print_else(const char *format, int *i, int *len)
{
	if (format[*i] == '%' && format[*i + 1] == '%')
		(*i)++;
	if (ft_putchar_fd(format[*i], 1, len) == -1)
		return (-1);
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	arg_ptr;
	int		total_len;
	int		i;
	int		ret;

	va_start(arg_ptr, format);
	total_len = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1] != '%' && format[i + 1])
			ret = print_format(arg_ptr, format[++i], &total_len);
		else
			ret = print_else(format, &i, &total_len);
		if (ret == -1 || total_len == -1)
		{
			va_end(arg_ptr);
			return (-1);
		}
		i++;
	}
	va_end(arg_ptr);
	return (total_len);
}

// int	main(void)
// {
// 	long long	i;
// 	int	len;
// 	int	len2;
// 	// char	*str = "hello world";
// 	// char	c = 's';

// 	i = 324;
// 	len = ft_printf("%c \n", 'x');
// 	ft_printf("%d\n", len);
// 	len2 = printf("%c \n", 'x');
// 	ft_printf("%d\n", len2);
// 	ft_printf("%p\n", (void *)-14523);
// 	return (0);
// }
