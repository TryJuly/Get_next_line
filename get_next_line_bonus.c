/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strieste <strieste@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 13:58:10 by strieste          #+#    #+#             */
/*   Updated: 2025/10/24 16:16:45 by strieste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*sort_stock(char **stock, int fd);
char	*fill_stock(int fd, char **stock, char **buffer);
size_t	ft_strchr_n(const char *s, int c);

char	*get_next_line(int fd)
{
	static char	*stock[OPEN_MAX];
	char		*line;
	char		*buffer;

	if (!stock[fd])
		stock[fd] = ft_strdup("");
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	stock[fd] = fill_stock(fd, &stock[fd], &buffer);
	free(buffer);
	if (!stock[fd])
	{
		free(stock[fd]);
		stock[fd] = NULL;
		return (NULL);
	}
	line = sort_stock(&stock[fd], fd);
	if (!line)
		return (NULL);
	return (line);
}

char	*sort_stock(char **stock, int fd)
{
	char	*line;
	char	*temp;
	ssize_t	count;

	count = 0;
	temp = stock[fd];
	count = 0;
	line = NULL;
	while (temp[count] != ((char) '\n') && temp[count])
		count++;
	if ((temp[count] == ((char) '\n') && temp[count]) || temp[count] == '\0')
	{
		count++;
		line = ft_substr(temp, 0, count);
		if (!line)
			return (NULL);
	}
	stock[fd] = ft_substr(temp, count, ft_strlen(temp));
	free(temp);
	if (stock[fd] == ((char) '\0') || !stock[fd])
	{
		free(stock[fd]);
		stock[fd] = NULL;
	}
	return (line);
}

char	*fill_stock(int fd, char **stock, char **buffer)
{
	char	*temp;
	ssize_t	state_fd;

	state_fd = 1;
	while (state_fd > 0)
	{
		state_fd = read(fd, *buffer, BUFFER_SIZE);
		if (state_fd == -1)
			return (NULL);
		((*buffer)[state_fd]) = '\0';
		temp = stock[fd];
		stock[fd] = ft_strjoin(stock[fd], *buffer);
		free(temp);
		if (!*stock[fd])
			return (NULL);
		if (ft_strchr_n(stock[fd], '\n'))
			break ;
	}
	return (stock[fd]);
}

size_t	ft_strchr_n(const char *s, int c)
{
	size_t	count;

	if (!s)
		return (0);
	if ((unsigned char)c == '\0' && s)
		return (ft_strlen(s));
	count = 0;
	while (s[count])
	{
		if (s[count] == (unsigned char)c)
			return (1);
		count++;
	}
	return (0);
}

// int	main(void)
// {
//     int	fd1 = open("file1.txt", O_RDONLY);
//     int	fd2 = open("file2.txt", O_RDONLY);
//     char	*line1;
//     char	*line2;

//     line1 = get_next_line(fd1);
//     printf("fd1: %s", line1);
//     free(line1);

//     line2 = get_next_line(fd2);
//     printf("fd2: %s", line2);
//     free(line2);

//     line1 = get_next_line(fd1);
//     printf("fd1: %s", line1);
//     free(line1);

//     line2 = get_next_line(fd2);
//     printf("fd2: %s", line2);
//     free(line2);

//     close(fd1);
//     close(fd2);
// }
