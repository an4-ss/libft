/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arokhsi <arokhsi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 17:38:47 by arokhsi           #+#    #+#             */
/*   Updated: 2024/11/11 18:22:25 by arokhsi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	get_length(const char *s)
{
	if (s)
	{
		return (ft_strlen(s));
	}
	return (0);
}

void	copy_string(const char *src, char *dest, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		dest[i] = src[i];
		i++;
	}
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*str;

	s1_len = get_length(s1);
	s2_len = get_length(s2);
	str = malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!str)
		return (NULL);
	copy_string(s1, str, s1_len);
	copy_string(s2, str + s1_len, s2_len);
	str[s1_len + s2_len] = '\0';
	return (str);
}
