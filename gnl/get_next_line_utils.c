/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabda <aabda@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 11:20:49 by aabda             #+#    #+#             */
/*   Updated: 2022/08/14 11:30:44 by aabda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = -1;
	while (s[++i] != (char)c)
		if (s[i] == 0)
			return (NULL);
	return ((char *)&s[i]);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	if (!s1)
		return (ft_strdup(s2));
	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (!str)
		return (NULL);
	i = -1;
	while (s1 && s1[++i])
		str[i] = s1[i];
	j = 0;
	while (s2 && s2[j])
	{
		str[i] = s2[j++];
		i++;
	}
	str[i] = '\0';
	free((char *)s1);
	return (str);
}

char	*ft_strdup(const char *s)
{
	char	*str;
	int		i;

	if (!s[0])
		return (NULL);
	str = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (s[i])
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	if (ft_strlen(s) < len)
		len = ft_strlen(s);
	if (!s)
		return (NULL);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	if (start > (unsigned int)ft_strlen(s))
	{
		str[0] = '\0';
		return (str);
	}
	i = 0;
	while (s[start] && (i < len))
	{
		str[i] = s[start];
		i++;
		start++;
	}
	str[i] = '\0';
	return (str);
}
