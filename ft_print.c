/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iuhara <iuhara@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 13:58:29 by iuhara            #+#    #+#             */
/*   Updated: 2024/07/06 15:02:34 by iuhara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar_fd(int c, int fd, int *len)
{
	if (write(fd, &c, 1) != 1)
		return (-1);
	(*len)++;
	return (0);
}

int	ft_putstr_fd(char *str, int fd, int *len)
{
	if (!str)
		str = "(null)";
	while (*str)
	{
		if (ft_putchar_fd(*str, fd, len) == -1)
			return (-1);
		str++;
	}
	return (0);
}
