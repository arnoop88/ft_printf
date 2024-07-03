/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apodader <apodader@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 13:59:21 by apodader          #+#    #+#             */
/*   Updated: 2023/02/20 14:01:10 by apodader         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_nbr(int nbr)
{
	int		len;
	char	*str;

	str = ft_itoa(nbr);
	if (!str)
		return (-1);
	len = ft_print_str(str);
	free(str);
	return (len);
}
