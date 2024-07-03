/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apodader <apodader@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 15:58:41 by apodader          #+#    #+#             */
/*   Updated: 2023/02/20 16:02:56 by apodader         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "./libft/libft.h"

int	ft_printf(const char *str, ...);
int	ft_formats(va_list args, const char c);
int	ft_print_char(char c);
int	ft_print_str(char *str);
int	ft_print_ptr(unsigned long ptr);
int	put_hex(unsigned long ptr);
int	ft_print_lower_hex(unsigned long nbr);
int	ft_print_upper_hex(unsigned long nbr);
int	put_hex_2(unsigned long ptr);
int	ft_print_nbr(int nbr);
int	ft_print_unsigned(unsigned int nbr);
int	ft_hexlen(unsigned long nbr);

#endif
