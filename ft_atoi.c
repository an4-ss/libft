/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arokhsi <arokhsi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 12:52:54 by arokhsi           #+#    #+#             */
/*   Updated: 2024/11/15 20:23:18 by arokhsi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

static int	ft_skip(const char *str, int *sign)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t'
		|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
	{
		i++;
	}
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
	int				sign;
	int				i;
	long			nbr;
	unsigned long	tmp_nbr;

	sign = 1;
	nbr = 0;
	tmp_nbr = 0;
	i = ft_skip(str, &sign);
	while (str[i] >= '0' && str[i] <= '9')
	{
		tmp_nbr = tmp_nbr * 10 + (str[i] - '0');
		if (tmp_nbr > LONG_MAX && sign == 1)
			return (-1);
		if (tmp_nbr > (unsigned long)(-LONG_MIN) && sign == -1)
			return (0);
		i++;
	}
	nbr = tmp_nbr * sign;
	return (nbr);
}
