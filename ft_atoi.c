/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arokhsi <arokhsi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 12:52:54 by arokhsi           #+#    #+#             */
/*   Updated: 2024/11/23 14:22:11 by arokhsi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	return_overflow(int sign)
{
	if (sign == 1)
		return (-1);
	if (sign == -1)
		return (0);
	return (0);
}

static int	skip(const char *str, int *sign)
{
	int	i;

	i = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			*sign = -1;
		i++;
	}
	return (i);
}

int	ft_atoi(const char *str)
{
	int			i;
	int			sign;
	long long	nbr;
	long long	tmp;

	sign = 1;
	i = skip (str, &sign);
	nbr = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		tmp = nbr * 10 + str[i] - '0';
		if (tmp < nbr)
			return (return_overflow(sign));
		nbr = nbr * 10 + str[i] - '0';
		i++;
	}
	return (nbr * sign);
}
