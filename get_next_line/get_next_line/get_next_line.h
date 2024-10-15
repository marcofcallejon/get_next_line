/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marfern3 <marfern3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 14:25:23 by marcofernan       #+#    #+#             */
/*   Updated: 2024/10/15 13:50:16 by marfern3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

const int BUFFER_SIZE = 42;
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>

char read_into_buffer (int fd, char *buffer);
char *append_to_line (char *line, char *buffer);
char	*save_remaining(char *buffer, char **remaining);
char	*get_next_line(int fd);
