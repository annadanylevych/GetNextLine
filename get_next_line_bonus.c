/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adanylev <adanylev@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 11:38:20 by adanylev          #+#    #+#             */
/*   Updated: 2023/10/05 12:28:32 by adanylev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*line_extraction(char *storage)
{
	char	*line;
	int		i;

	i = 0;
	while (storage[i] && storage[i] != '\n')
		i++;
	if (storage[i] == '\n')
		i++;
	line = malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (storage[i] && storage[i] != '\n')
	{
		line[i] = storage[i];
		i++;
	}
	if (storage[i] && storage[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*update_storage(char *storage, char *line)
{
	char	*tmp;

	if (storage[0] == '\0')
	{
		free(storage);
		return (NULL);
	}
	tmp = ft_substr(storage, ft_strlen(line), ft_strlen(storage)
			- ft_strlen(line));
	free(storage);
	return (tmp);
}

char	*ft_read(int fd, char *storage)
{
	char	*buffer;
	int		mbytesread;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
	{
		free(storage);
		return (NULL);
	}
	buffer[0] = '\0';
	mbytesread = 1;
	while (mbytesread > 0 && !ft_strchr(buffer, '\n'))
	{
		mbytesread = read(fd, buffer, BUFFER_SIZE);
		if (mbytesread == -1)
		{
			free(buffer);
			free(storage);
			return (NULL);
		}
		buffer[mbytesread] = '\0';
		storage = ft_strjoin(storage, buffer);
	}
	free(buffer);
	return (storage);
}

char	*get_next_line(int fd)
{
	static char	*storage[OPEN_MAX] = NULL;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= OPEN_MAX)
		return (NULL);
	if (!storage[fd] || (storage[fd] && !ft_strchr(storage[fd], '\n')))
		storage[fd] = ft_read(fd, storage[fd]);
	if (!storage[fd])
		return (NULL);
	line = line_extraction(storage[fd]);
	if (!line)
	{
		free(storage[fd]);
		storage[fd] = NULL;
		return (NULL);
	}
	if (*line == '\0')
	{
		free(line);
		line = NULL;
	}
	storage[fd] = update_storage(storage[fd], line);
	return (line);
}
/*
int	main(void)
{
	int fd1, fd2, fd3;
	char *line;

	fd1 = open("file1.txt", O_RDONLY);
	fd2 = open("file2.txt", O_RDONLY);
	fd3 = open("file3.txt", O_RDONLY);
	printf("Reading from Source 1:\n");
	line = get_next_line(fd1);
	printf("Line: %s\n", line);
	free(line);
	close(fd1);
	printf("Reading from Source 2:\n");
	line = get_next_line(fd2);
	printf("Line: %s\n", line);
	free(line);
	close(fd2);
	printf("Reading from Source 3:\n");
	line = get_next_line(fd3);
	printf("Line: %s\n", line);
	free(line);
	close(fd3);
	return (0);
}*/
