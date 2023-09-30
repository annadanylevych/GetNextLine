/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adanylev <adanylev@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 20:30:41 by adanylev          #+#    #+#             */
/*   Updated: 2023/09/30 23:13:57 by adanylev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	char	*join;

	i = 0;
//	printf("Here is strjoin the len of buffer is %d and buffer is %s", ft_strlen(s2), s2);
	if (!s1)
	{
		s1 = malloc(sizeof(char) * 1);
		if (!s1)
			return (NULL);
		s1[0] = '\0';
	}
	join = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
//	printf("Malloc success!");
	if (!join)
		return (NULL);
//	printf("in strjoin storage is %s and buffer is %s", s1, s2);
	while (i < ft_strlen(s1) + ft_strlen(s2))
	{
		if (i < ft_strlen(s1))
			join[i] = s1[i];
		else
			join[i] = s2[i - ft_strlen(s1)];
		i++;
	}
	join[i] = '\0';
	free(s1);
	return (join);
}

char	*line_extraction(char *storage)
{
	char	*line;
	int		i;
	int		a;
	int		b;

	a = 0;
	i = 0;
	b = 0;
	while (storage[i] && storage[i] != '\n')
		i++;
	line = malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	while (a < i)
	{
		line[b] = storage[a];
		b++;
		a++;
	}
	if (storage[a] == '\n')
		line[b++] = '\n';
	line[b] = '\0';
	return (line);
}

char	*ft_substr(char *s, int start, int len)
{
	char			*sub;
	int				i;

	i = 0;
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	sub = malloc(sizeof(char) * (len + 1));
	if (!sub)
		return (NULL);
	while (i < len)
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}
