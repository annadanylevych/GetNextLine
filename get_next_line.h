/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adanylev <adanylev@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 21:01:21 by adanylev          #+#    #+#             */
/*   Updated: 2023/09/29 22:33:13 by adanylev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#define BUFFER_SIZE 42
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);

#endif


