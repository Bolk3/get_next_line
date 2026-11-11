/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resonnet <renald.sonnet@learner.42.tech>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 20:18:45 by resonnet          #+#    #+#             */
/*   Updated: 2026/11/11 12:34:52 by resonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stddef.h>
#include <stdlib.h>

void	set_string(char *string, char *stack, char *buffer)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (stack && stack[i])
	{
		string[i] = stack[i];
		i++;
	}
	while (buffer[j])
	{
		string[i + j] = buffer[j];
		j++;
	}
	string[i + j] = 0;
}

int	ft_strcmp(char *s1, char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s)
{
	char	*result;
	size_t	i;

	i = 0;
	result = malloc(ft_strlen(s) + 1);
	if (!result)
		return (NULL);
	while (s[i])
	{
		result[i] = s[i];
		i++;
	}
	result[i] = 0;
	return (result);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	i;
	size_t	strsize;
	size_t	size;

	i = 0;
	strsize = ft_strlen(s);
	if (start > strsize)
		return (ft_strdup(""));
	else if (start + len > strsize)
		size = len - (start + len - strsize);
	else
		size = len;
	res = malloc(size + 1);
	if (!res)
		return (NULL);
	while (s[start + i] && i < size)
	{
		res[i] = s[start + i];
		i++;
	}
	res[i] = 0;
	return (res);
}
