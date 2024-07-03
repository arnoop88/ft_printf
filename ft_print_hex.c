/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apodader <apodader@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 13:57:09 by apodader          #+#    #+#             */
/*   Updated: 2023/02/20 13:59:03 by apodader         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	put_hex_2(unsigned long ptr)
{
	char	*str;
	int		err;

	str = "0123456789ABCDEF";
	if (ptr >= 16)
	{
		err = put_hex_2(ptr / 16);
		if (err == -1)
			return (-1);
		err = put_hex_2(ptr % 16);
	}
	else
		err = ft_print_char(str[ptr]);
	if (err == -1)
		return (err);
	return (0);
}

int	ft_print_lower_hex(unsigned long nbr)
{
	int	len;
	int	err;

	len = ft_hexlen((unsigned int)nbr);
	err = put_hex((unsigned int)nbr);
	if (err == -1)
		return (-1);
	return (len);
}

int	ft_print_upper_hex(unsigned long nbr)
{
	int	len;
	int	err;

	len = ft_hexlen((unsigned int)nbr);
	err = put_hex_2((unsigned int)nbr);
	if (err == -1)
		return (-1);
	return (len);
}
