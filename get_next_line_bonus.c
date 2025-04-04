/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmetreve <zmetreve@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 13:53:49 by zmetreve          #+#    #+#             */
/*   Updated: 2024/10/29 08:36:05 by zmetreve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_join_and_free(char *text, char *buffer)
{
	char	*temp;

	temp = ft_strjoin(text, buffer);
	free(text);
	return (temp);
}

char	*read_first_line(int fd, char *text)
{
	char	*buffer;
	int		bytes_read;

	if (!text)
		text = ft_calloc(1, 1);
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free (text);
			free (buffer);
			return (NULL);
		}
		buffer[bytes_read] = 0;
		text = ft_join_and_free(text, buffer);
		if (ft_strchr(text, '\n'))
			break ;
	}
	free (buffer);
	return (text);
}

char	*get_line_here(char *text)
{
	int		i;
	char	*str;

	i = 0;
	if (!text[i])
		return (NULL);
	while (text[i] && text[i] != '\n')
		i++;
	str = ft_calloc(i + 2, sizeof(char));
	i = 0;
	while (text[i] && text[i] != '\n')
	{
		str[i] = text[i];
		i++;
	}
	if (text[i] && text[i] == '\n')
		str[i++] = '\n';
	return (str);
}

char	*clean_first_line(char *text)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	while (text[i] && text[i] != '\n')
		i++;
	if (!text[i])
	{
		free (text);
		return (NULL);
	}
	str = ft_calloc((ft_strlen(text) - i + 1), sizeof(*text));
	if (!str)
		return (NULL);
	while (text[++i])
		str[j++] = text[i];
	str[j] = '\0';
	free (text);
	return (str);
}

char	*get_next_line(int fd)
{
	char		*output_text;
	static char	*text[FOPEN_MAX];

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > FOPEN_MAX)
		return (NULL);
	text[fd] = read_first_line(fd, text[fd]);
	if (!text[fd])
		return (NULL);
	output_text = get_line_here(text[fd]);
	text[fd] = clean_first_line(text[fd]);
	return (output_text);
}

int	main(void)
{

	printf("%d", FOPEN_MAX);
	int		f1 = open("test1.txt", O_RDONLY);
	int		f2 = open("test2.txt", O_RDONLY);
//	int		f3 = open("test3.txt", O_RDONLY);
//	int		f4 = open("test4.txt", O_RDONLY);
//	int		f5 = open("test5.txt", O_RDONLY);
//	int		f6 = open("test6.txt", O_RDONLY);
	char	*line;

	printf("%s", line = get_next_line(f1));
	free(line);
	printf("%s", line = get_next_line(f2));
	free(line);
//	printf("%s", line = get_next_line(f3));
//	free(line);
//	printf("%s", line = get_next_line(f4));
//	free(line);
//	printf("%s", line = get_next_line(f5));
//	free(line);
//	printf("%s", line = get_next_line(f6));
//	free(line);
	close(f1);
	close(f2);
	return (0);
}
