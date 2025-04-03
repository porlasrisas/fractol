/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guigonza <guigonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 12:42:19 by guigonza          #+#    #+#             */
/*   Updated: 2024/10/14 19:48:56 by guigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <ctype.h>
# include <limits.h>

int		ft_printf(const char *formart, ...);
int		ft_putchar_fd_print(char c, int fd);
int		ft_putstr_fd_print(char *s, int fd);
int		ft_putnbr_fd_print(int n, int fd);
int		ft_putnbr_hex_print(unsigned long n, int uppercase);

#endif