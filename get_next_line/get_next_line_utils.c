/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcofernandezcallejon <marcofernandezc    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 12:14:20 by marcofernan       #+#    #+#             */
/*   Updated: 2024/10/14 22:15:40 by marcofernan      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char read_into_buffer (int fd, char *buffer)
{
	int bytes_read;

	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read == -1)
		return(NULL);
	buffer[bytes_read] = '\0';
	return (bytes_read);
}

char *append_to_line (char *line, char *buffer)
{
	char	*new_line;

	if (line == NULL)
		return (strdup(buffer));
	new_line = (char *)malloc(strlen(line) + strlen(buffer) + 1);
	if(!new_line)
		return(NULL);
	strcpy(new_line, line);
	strcat(new_line, buffer);
	free(line);
	return (new_line);
}

char	*save_remaining(char *buffer, char **remaining)
{
	char *newline_pos;

	newline_pos = strchr (buffer, '\n');
	if (newline_pos)
	{
		*newline_pos = '\0';
		free (*remaining);
		remaining = strdup (newline_pos + 1);
	}
	return (newline_pos ? strdup(buffer) : NULL);
}