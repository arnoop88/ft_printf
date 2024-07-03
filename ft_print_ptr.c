/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apodader <apodader@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 13:16:48 by apodader          #+#    #+#             */
/*   Updated: 2023/02/20 14:01:57 by apodader         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexlen(unsigned long nbr)
{
	int	len;

	len = 0;
	if (nbr == 0)
		return (1);
	while (nbr)
	{
		nbr /= 16;
		len++;
	}
	return (len);
}

int	put_hex(unsigned long ptr)
{
	char	*str;
	int		err;

	str = "0123456789abcdef";
	if (ptr >= 16)
	{
		err = put_hex(ptr / 16);
		if (err == -1)
			return (-1);
		err = put_hex(ptr % 16);
	}
	else
		err = ft_print_char(str[ptr]);
	if (err == -1)
		return (err);
	return (0);
}

int	ft_print_ptr(unsigned long ptr)
{
	int	len;
	int	err;

	len = 2;
	err = write(1, "0x", 2);
	if (err == -1)
		return (-1);
	if (!ptr)
	{
		err = ft_print_char('0');
		if (err == -1)
			return (-1);
		return (3);
	}
	len += ft_hexlen(ptr);
	err = put_hex(ptr);
	if (err == -1)
		return (-1);
	return (len);
}
