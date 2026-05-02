/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrass <magrass@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 10:51:37 by magrass           #+#    #+#             */
/*   Updated: 2026/05/02 14:24:55 by magrass          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdbool.h>
#include <stddef.h>
#include <unistd.h>
#ifdef TESTING
# include <fcntl.h>
#endif

char	*get_first_line(char *ptr, bool is_buf)
{
	size_t	i;
	char	*line;

	if (!ptr || !ptr[0])
	{
		if (!is_buf)
			free(ptr);
		return (NULL);
	}
	i = 0;
	while (ptr[i] && ptr[i] != '\n')
		i++;
	if (ptr[i] == '\n')
		i++;
	line = malloc(i + 1);
	ft_memcpy(line, ptr, i);
	line[i] = '\0';
	if (!is_buf)
		free(ptr);
	return (line);
}

void	rm_before_first_endl(size_t bSize, char buf[static bSize])
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < bSize && buf[i] && buf[i] != '\n')
		i++;
	if (i >= bSize || !buf[i])
		return ;
	i++;
	j = 0;
	while (i < bSize)
		buf[j++] = buf[i++];
	buf[j] = '\0';
}

char	*get_next_line(int fd)
{
	static char			buf[BUFFER_SIZE + 1] = {0};
	ssize_t				bytes_read;
	char				*return_ptr;

	return_ptr = NULL;
	if (find_char('\n', buf) != -1)
	{
		return_ptr = get_first_line(buf, true);
		rm_before_first_endl(sizeof(buf), buf);
		return (return_ptr);
	}
	if (buf[0])
		ft_str_merge(&return_ptr, buf);
	bytes_read = 1;
	while (bytes_read > 0 && find_char('\n', return_ptr) == -1)
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (bytes_read == -1)
			return ((buf[0] = '\0', free(return_ptr), NULL));
		buf[bytes_read] = '\0';
		ft_str_merge(&return_ptr, buf);
	}
	rm_before_first_endl(sizeof(buf), buf);
	return (get_first_line(return_ptr, false));
}

#ifdef TESTING

int	main(int argc, char *argv[])
{
	int		fd;
	char	*next_line;

	if (argc != 2)
	{
		write(1, "2 arguments pls\n", 16);
		return (1);
	}
	fd = open(argv[1], O_RDONLY);
	while (true)
	{
		next_line = get_next_line(fd);
		if (!next_line || !next_line[0])
			break ;
		write(1, next_line, ft_strlen(next_line));
		free(next_line);
	}
}

#endif