/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iuhara <iuhara@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 15:55:38 by iuhara            #+#    #+#             */
/*   Updated: 2024/07/06 15:38:22 by iuhara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <limits.h>
# include <stdarg.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

int	ft_putnbr_fd(unsigned long long num, const char *base, int fd, int *len);
int	ft_putnbr_signed_fd(long long num, const char *base, int fd, int *len);
int	ft_putchar_fd(int c, int fd, int *len);
int	ft_putstr_fd(char *str, int fd, int *len);
int	print_format(va_list arg_ptr, char specifier, int *len);
int	print_else(const char *format, int *i, int *len);
int	ft_printf(const char *format, ...);

#endif