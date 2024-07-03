/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apodader <apodader@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 13:15:35 by apodader          #+#    #+#             */
/*   Updated: 2023/02/09 13:25:34 by apodader         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char(char c)
{
	return (write (1, &c, 1));
}

int	ft_formats(va_list args, const char c)
{
	int	len;

	len = 0;
	if (c == 'c')
		len += ft_print_char(va_arg(args, int));
	else if (c == 's')
		len += ft_print_str(va_arg(args, char *));
	else if (c == 'p')
		len += ft_print_ptr(va_arg(args, unsigned long));
	else if (c == 'd' || c == 'i')
		len += ft_print_nbr(va_arg(args, int));
	else if (c == 'u')
		len += ft_print_unsigned(va_arg(args, unsigned int));
	else if (c == 'x')
		len += ft_print_lower_hex(va_arg(args, unsigned long));
	else if (c == 'X')
		len += ft_print_upper_hex(va_arg(args, unsigned long));
	else if (c == '%')
		len += ft_print_char(c);
	return (len);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		len;
	va_list	args;
	int		err;

	i = 0;
	len = 0;
	va_start (args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			err = ft_formats(args, str[i + 1]);
			i++;
		}
		else
			err = ft_print_char(str[i]);
		if (err == -1)
			return (-1);
		else
			len += err;
		i++;
	}
	va_end (args);
	return (len);
}
