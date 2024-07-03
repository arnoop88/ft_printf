/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apodader <apodader@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 14:01:28 by apodader          #+#    #+#             */
/*   Updated: 2023/02/20 14:01:32 by apodader         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_uitoa(unsigned int nbr)
{
	int		len;
	int		i;
	char	*str;

	i = 1;
	if (nbr < 0)
		nbr = 4294967295 - nbr;
	len = ft_nbrlen((long long)nbr);
	str = (char *)malloc(len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	while (i <= len)
	{
		str[len - i] = nbr % 10 + 48;
		nbr /= 10;
		i++;
	}
	return (str);
}

int	ft_print_unsigned(unsigned int nbr)
{
	int		len;
	char	*str;

	str = ft_uitoa(nbr);
	if (!str)
		return (-1);
	len = ft_print_str(str);
	free(str);
	return (len);
}
