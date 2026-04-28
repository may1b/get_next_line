/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrass <magrass@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 10:51:29 by magrass           #+#    #+#             */
/*   Updated: 2026/04/28 10:56:21 by magrass          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# ifndef  BUFFER_SIZE
#  define  BUFFER_SIZE 1024
# endif

#include <unistd.h>

char	*get_next_line(int fd);

#endif