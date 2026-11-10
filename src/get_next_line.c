/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resonnet <renald.sonnet@learner.42.tech>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 19:58:03 by resonnet          #+#    #+#             */
/*   Updated: 2026/11/10 21:02:12 by resonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <get_next_line.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
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
	if (ft_strcmp("", (char *)stack) == 0)
		return (NULL);
	while (stack[i] && stack[i] != '\n')
		i++;
	return (ft_substr(stack, 0, i+1));
}

char	*concatenate(char *stack, char *buffer)
{
	char	*result;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!stack)
		return (ft_strdup(buffer));
	result = malloc(ft_strlen(stack) + ft_strlen(buffer) + 1);
	if (!result)
		return (NULL);
	while (stack[i])
	{
		result[i] = stack[i];
		i++;
	}
	while (buffer[j])
	{
		result[i + j] = buffer[j];
		j++;
	}
	result[i + j] = 0;
	free(stack);
	return (result);
}

char	*remove_start(char *stack)
{
	char	*result;
	size_t	i;

	i = 0;
	while (stack[i] && stack[i] != '\n')
		i++;
	result = ft_substr(stack, i + 1, ft_strlen(stack));
	free(stack);
	return (result);
}

char	*get_next_line(int fd)
{
	static char	*stack = NULL;
	ssize_t		read_size;
	char		buffer[BUFFER_SIZE + 1];
	char		*result;

	read_size = read(fd, buffer, BUFFER_SIZE);
	while (read_size)
	{
		buffer[read_size] = 0;
		stack = concatenate(stack, buffer);
		if (!stack)
			return (NULL);
		if (is_line(stack) != -1)
			break ;
		read_size = read(fd, buffer, BUFFER_SIZE);
	}
	result = get_line(stack);
	stack = remove_start(stack);
	return (result);
}

int main(void)
{
	char	*line;
	FILE	*file = fopen("./test.txt", "r");
	int		fd;

	if (file)
		fd = fileno(file);
	while ((line = get_next_line(fd))){
		printf("%s\n", line);
		free(line);
	}
}
