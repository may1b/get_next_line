/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrass <magrass@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 10:51:50 by magrass           #+#    #+#             */
/*   Updated: 2026/05/02 13:00:24 by magrass          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include <sys/types.h>
#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (!dest && !src)
		return (dest);
	i = 0;
	while (i < n)
	{
		((char *)dest)[i] = ((const char *)src)[i];
		i++;
	}
	return (dest);
}

/* Warning: frees `merge_into`, does not free `to_merge` */
void	ft_str_merge(char **merge_into, char *to_merge)
{
	char	*new_str;
	size_t	i;
	size_t	j;

	new_str = malloc(ft_strlen(*merge_into) + ft_strlen(to_merge) + 1);
	i = 0;
	while (*merge_into && (*merge_into)[i])
	{
		new_str[i] = (*merge_into)[i];
		i++;
	}
	j = 0;
	while (to_merge[j])
		new_str[i++] = to_merge[j++];
	new_str[i] = '\0';
	free(*merge_into);
	*merge_into = new_str;
}

ssize_t	find_char(char to_find, char *haystack)
{
	ssize_t	i;

	i = 0;
	if (!haystack)
		return (-1);
	while (haystack[i])
	{
		if (haystack[i] == to_find)
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_strdup(const char *s)
{
	size_t	str_size;
	char	*new_str;

	str_size = ft_strlen(s);
	new_str = malloc(str_size + 1);
	if (!new_str)
		return (NULL);
	ft_memcpy(new_str, s, str_size + 1);
	return (new_str);
}
