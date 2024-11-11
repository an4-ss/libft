/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arokhsi <arokhsi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 13:39:47 by arokhsi           #+#    #+#             */
/*   Updated: 2024/11/11 18:10:43 by arokhsi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	in_set(char c, const char *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	size_t	start;
	size_t	end;
	size_t	i;
	char	*trimmed;

	i = 0;
	start = 0;
	end = 0;
	if (!s1 || !set)
		return (NULL);
	while (s1[end])
		end++;
	while (s1[start] && in_set(s1[start], set))
		start++;
	while (end > start && in_set(s1[end - 1], set))
		end--;
	trimmed = malloc(sizeof(char) * (end - start + 1));
	if (!trimmed)
		return (NULL);
	while (start < end)
		trimmed[i++] = s1[start++];
	trimmed[i] = '\0';
	return (trimmed);
}
