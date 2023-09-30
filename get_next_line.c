/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adanylev <adanylev@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 13:27:56 by adanylev          #+#    #+#             */
/*   Updated: 2023/09/30 23:13:53 by adanylev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
char *update_storage(char *storage, char *line)
{
	char	*tmp;

	tmp = ft_substr(storage, ft_strlen(line) + 1, ft_strlen(storage)
			- ft_strlen(line));
	free(storage);
	storage = tmp;
	return (storage);
}

char	*ft_read(int fd, char *storage)
{
	char	*buffer;
	int		mbytesread;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	buffer[0] = '\0';
	mbytesread = 1;
	while (mbytesread > 0 && !ft_strchr(buffer, '\n'))
	{
		mbytesread = read(fd, buffer, BUFFER_SIZE);
//		printf("Here the buffer is %s", buffer);
		if (mbytesread == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[mbytesread] = '\0';
		storage = ft_strjoin(storage, buffer);
	}
//	printf("here the storage is: %s", storage);
	free(buffer);
//	printf("storage in fd read is: %s\n", storage);
	return (storage);
}

char	*get_next_line(int fd)
{
	static char	*storage;
	char		*line;
	
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!storage || (storage && !ft_strchr(storage, '\n')))
		storage = ft_read(fd, storage);
	if (!storage)
		return (NULL);
	line = line_extraction(storage);
	if (!line)
	{
		free(storage);
		return (NULL);
	}
//	printf("line is:%s\n", line);
	storage = update_storage(storage, line);	
//	printf("updated storage: %s\n", storage);
	return (line);
}
/*
int	main(void)
{
	char *line;
	int fd = open("test.txt", O_RDWR);
	line = get_next_line(fd);
	printf("%s\n", line);
	free(line);
	line = get_next_line(fd);
	printf("%s\n", line);
	free(line);	
	line = get_next_line(fd);
	printf("%s\n", line);
	free(line);	
	line = get_next_line(fd);
	printf("%s\n", line);
	free(line);
	return (0);
}*/
