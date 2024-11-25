/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marfern3 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 17:11:28 by marfern3          #+#    #+#             */
/*   Updated: 2024/11/25 17:11:31 by marfern3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_freeall(char **s)
{
	free(*s);
	*s = NULL;
	return (NULL);
}

char	*ft_get_line(char *s)
{
	int		i;
	char	*newline;

	i = 0;
	if (!s || !*s)
		return (NULL);
	while (s[i] && s[i] != '\n')
		i++;
	if (s[i] == '\n')
		i++;
	newline = ft_substr(s, 0, i);
	return (newline);
}

char	*ft_cleanstr(char *s)

{
	int		i;
	char	*newstr;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	if (s[i] == '\n')
		i++;
	if (s[i] == '\0')
		return (ft_freeall(&s));
	newstr = ft_substr(s, i, ft_strlen(s) - i);
	free(s);
	return (newstr);
}

char	*ft_readbuffer(int fd, char *s)
{
	char	*buffer;
	int		bytes;

	bytes = 1;
	while (!ft_strchr(s, '\n') && bytes > 0)
	{
		buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (!buffer)
			return (ft_freeall(&s));
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes < 1)
		{
			free(buffer);
			if (bytes < 0)
				return (ft_freeall(&s));
			return (s);
		}
		buffer[bytes] = '\0';
		s = ft_strjoin(s, buffer);
		free(buffer);
	}
	return (s);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str = ft_readbuffer(fd, str);
	if (!str)
		return (NULL);
	line = ft_get_line(str);
	if (!line)
		return (ft_freeall(&str));
	str = ft_cleanstr(str);
	return (line);
}

/*int	main(void)
{
	int fd = open("giant_line_nl.txt", O_RDONLY);
	char *line;

	line = get_next_line(fd);
	printf("1%s\n", line);
	free(line);
	line = get_next_line(fd);
	printf("2%s\n", line);
	free(line);
	line = get_next_line(fd);
	printf("3%s\n", line);
	free(line);
	line = get_next_line(fd);
	printf("4%s\n", line);
	free(line);
	line = get_next_line(fd);
	printf("5%s\n", line);
	free(line);
	line = get_next_line(fd);
	printf("6%s\n", line);
	free(line);
	line = get_next_line(fd);
	printf("7%s\n", line);
	free(line);
	line = get_next_line(fd);
	printf("8%s\n", line);
	free(line);
	line = get_next_line(fd);
	printf("9%s\n", line);
	free(line);
	line = get_next_line(fd);
	printf("10%s\n", line);
	free(line);
	line = get_next_line(fd);
	printf("1%s\n", line);
	free(line);
	line = get_next_line(fd);
	printf("2%s\n", line);
	free(line);
	line = get_next_line(fd);
	printf("3%s\n", line);
	free(line);
	line = get_next_line(fd);
	printf("4%s\n", line);
	free(line);
	line = get_next_line(fd);
	printf("5%s\n", line);
	free(line);
	line = get_next_line(fd);
	printf("6%s\n", line);
	free(line);
}*/
