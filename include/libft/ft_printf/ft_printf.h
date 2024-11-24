/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvittoz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 09:07:15 by jvittoz           #+#    #+#             */
/*   Updated: 2023/12/11 07:38:53 by jvittoz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>

int		ft_strlen(char *i);
void	ft_putchar(char c);
void	ft_putstr(char *s);
void	ft_putnbr(int i);
void	ft_putnbr_base(unsigned int i, char *base);
void	ft_putnbr_basep(unsigned long long i, char *base);
void	ft_putunbr(unsigned int i);
void	ft_putptr(void *p);
int		ft_count_int(int i);
int		ft_count_unsigned(unsigned int i);
int		ft_count_base(unsigned int i);
int		ft_count_ptr(void *p);
int		ft_print_c(int arg);
int		ft_print_s(char *arg);
int		ft_print_p(void *arg);
int		ft_print_d(int arg);
int		ft_print_i(int arg);
int		ft_print_u(unsigned int arg);
int		ft_print_x(unsigned int arg);
int		ft_print_xup(unsigned int arg);
int		ft_print_arg(va_list arg, char c);
int		ft_printf(const char *str, ...);
#endif
