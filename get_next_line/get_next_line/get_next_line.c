/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marfern3 <marfern3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 14:04:49 by marcofernan       #+#    #+#             */
/*   Updated: 2024/10/15 13:50:54 by marfern3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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