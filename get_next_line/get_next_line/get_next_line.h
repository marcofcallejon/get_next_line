/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marfern3 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 13:59:47 by marfern3          #+#    #+#             */
/*   Updated: 2024/10/15 13:59:52 by marfern3         ###   ########.fr       */
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
