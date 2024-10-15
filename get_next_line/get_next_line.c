/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcofernandezcallejon <marcofernandezc    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 14:04:49 by marcofernan       #+#    #+#             */
/*   Updated: 2024/10/14 12:28:30 by marcofernan      ###   ########.fr       */
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

char	*get_next_line(int fd)
{
	static char	*remaining;
	char 	buffer[BUFFER_SIZE + 1];
	char	*line = NULL;
	int		bytes_read;

	if (remaining)
	{
		line = strdup(remaining);
		free (remaining);
		remaining = NULL;
	}
	while ((bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[bytes_read] = '\0';
		if (save_remaining(buffer, &remaining)) // busca \n en el buffer, si lo encuentra divide el buffer en dos partes, antes y después de \n.
			return (append_to_line(line, buffer));
		line = append_to_line(line, buffer); // si no encuentra \n simplemente concatena el contenido de buffer al final de line y sigue buscando \n.
	}
	return (line && *line) ? line : NULL; // line es NULL si no hemos leido nada o ya hemos devuelto todas las lineas disponibles, *line verifica si la línea no está vacía.
}