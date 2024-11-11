/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arokhsi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 15:36:54 by arokhsi           #+#    #+#             */
/*   Updated: 2024/11/08 15:26:25 by arokhsi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count(const char *str, char c)
{
	int	flag;
	int	count;

	flag = 0;
	count = 0;
	while (*str)
	{
		if (*str == c)
			flag = 0;
		else if (flag == 0)
		{
			flag = 1;
			count++;
		}
		str++;
	}
	return (count);
}

static char	*ft_fill(const char *s, char c)
{
	int		len;
	char	*buff;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	buff = malloc(len + 1);
	if (!buff)
		return (NULL);
	ft_memcpy(buff, s, len);
	buff[len] = '\0';
	return (buff);
}

char	**ft_split(char const *s, char c)
{
	int		words;
	char	**buff;
	int		i;

	if (!s)
		return (NULL);
	words = ft_count(s, c);
	buff = malloc(sizeof (char *) * (words + 1));
	if (!buff)
		return (NULL);
	i = 0;
	while (i < words)
	{
		while (*s && *s == c)
			s++;
		buff[i++] = ft_fill(s, c);
		while (*s && *s != c)
			s++;
	}
	buff[words] = NULL;
	return (buff);
}
