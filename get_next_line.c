/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adanylev <adanylev@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 13:27:56 by adanylev          #+#    #+#             */
/*   Updated: 2023/09/29 22:35:39 by adanylev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

char	*ft_read(int fd, char *storage)
{
	char	*buffer;
	int	bytesRead;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!storage)
		return (NULL);
	buffer[0] = '\0';
	bytesRead = 1;
	while (bytesRead > 0/* && !ft_strchr(buffer, '\n')*/)
	{
		bytesRead = read(fd, buffer, BUFFER_SIZE);
		if (bytesRead <= 0)
		{
			free(buffer);
			return (NULL);
		}
		buffer[bytesRead] = '\0';
		storage = ft_strjoin(storage, buffer);
	}
	return (storage);
}

char	*get_next_line(int fd)
{	
	static char	*storage = NULL;
	char * line;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	else
		storage = ft_read(fd, storage);
	return (storage);
}

int	main()
{
	int fd = open("test.txt", O_RDWR);
	printf("%s", get_next_line(fd));
	return (0);
}
