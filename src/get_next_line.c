/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resonnet <renald.sonnet@learner.42.tech>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 19:58:03 by resonnet          #+#    #+#             */
/*   Updated: 2026/11/11 16:37:17 by resonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int	is_line(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*get_line(const char *stack)
{
	size_t	i;

	i = 0;
	if (!stack)
		return (NULL);
	if (ft_strcmp("", (char *)stack) == 0)
		return (NULL);
	while (stack[i] && stack[i] != '\n')
		i++;
	return (ft_substr(stack, 0, i + 1));
}

char	*concatenate(char *stack, char *buffer)
{
	char	*result;

	if (!stack)
		result = malloc(ft_strlen(buffer) + 1);
	else
		result = malloc(ft_strlen(stack) + ft_strlen(buffer) + 1);
	if (!result)
		return (NULL);
	set_string(result, stack, buffer);
	free(stack);
	return (result);
}

char	*remove_start(char *stack)
{
	char	*result;
	size_t	i;
	size_t	len;

	i = 0;
	if (!stack)
		return (NULL);
	if (ft_strlen(stack) == 0)
	{
		free(stack);
		return (NULL);
	}
	while (stack[i] && stack[i] != '\n')
		i++;
	len = ft_strlen(stack) - i;
	result = ft_substr(stack, i + 1, len);
	free(stack);
	return (result);
}

char	*get_next_line(int fd)
{
	static char	*stack[1024] = {NULL};
	ssize_t		read_size;
	char		buffer[BUFFER_SIZE + 1];
	char		*result;

	read_size = read(fd, buffer, BUFFER_SIZE);
	while (read_size > 0)
	{
		buffer[read_size] = 0;
		stack[fd] = concatenate(stack[fd], buffer);
		if (!stack[fd])
			return (NULL);
		if (is_line(stack[fd]) != -1)
			break ;
		read_size = read(fd, buffer, BUFFER_SIZE);
	}
	result = get_line(stack[fd]);
	stack[fd] = remove_start(stack[fd]);
	return (result);
}
