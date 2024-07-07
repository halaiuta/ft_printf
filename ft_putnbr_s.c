/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iuhara <iuhara@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 19:44:44 by iuhara            #+#    #+#             */
/*   Updated: 2024/07/06 15:12:25 by iuhara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_fd(unsigned long long num, const char *base, int fd, int *len)
{
	int	base_len;

	base_len = 0;
	while (base[base_len])
		base_len++;
	if (base_len < 2)
		return (-1);
	if (num >= (unsigned long long)base_len)
	{
		if (ft_putnbr_fd(num / base_len, base, fd, len) == -1)
			return (-1);
	}
	if (ft_putchar_fd(base[num % base_len], fd, len) == -1)
		return (-1);
	return (0);
}

int	ft_putnbr_signed_fd(long long num, const char *base, int fd, int *len)
{
	unsigned long long	abs_num;

	if (num < 0)
	{
		if (ft_putchar_fd('-', fd, len) == -1)
			return (-1);
		abs_num = (unsigned long long)(-num);
	}
	else
		abs_num = (unsigned long long)num;
	return (ft_putnbr_fd(abs_num, base, fd, len));
}
