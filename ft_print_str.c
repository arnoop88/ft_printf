/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apodader <apodader@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 13:17:03 by apodader          #+#    #+#             */
/*   Updated: 2023/02/09 13:25:12 by apodader         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_str(char *str)
{
	int	i;
	int	err;

	i = 0;
	if (!str)
		return (write(1, "(null)", 6));
	while (str[i])
	{
		err = ft_print_char(str[i]);
		if (err == -1)
			return (-1);
		i++;
	}
	return (i);
}
