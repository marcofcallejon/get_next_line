/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marfern3 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 14:00:43 by marfern3          #+#    #+#             */
/*   Updated: 2024/10/15 14:00:45 by marfern3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "get_next_line.h"

char read_into_buffer (int fd, char *buffer) //lee unn fragmento de datos desde un archivo y los coloca en el buffer.
{
	int bytes_read;

	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read == -1)
		return(NULL);
	buffer[bytes_read] = '\0';
	return (bytes_read);
}

char *append_to_line (char *line, char *buffer) //concatena dos cadenas: una linea previamente leida y unn nuevo fragmento de datos (buffer)
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

char	*save_remaining(char *buffer, char **remaining) //esta función busca un salto de linea (\n) en el buffer. Si lo encuentra lo guarda en remaining.
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
