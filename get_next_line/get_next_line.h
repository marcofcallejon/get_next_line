/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marfern3 <marfern3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 13:59:47 by marfern3          #+#    #+#             */
/*   Updated: 2024/10/15 16:06:09 by marfern3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  GET_NEXT_LINE
#define GET_NEXT_LINE

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 50
#endif

char read_into_buffer (int fd, char *buffer);
char *append_to_line (char *line, char *buffer);
char	*save_remaining(char *buffer, char **remaining);
char	*get_next_line(int fd);

#endif