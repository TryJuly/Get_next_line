/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strieste <strieste@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 13:42:50 by strieste          #+#    #+#             */
/*   Updated: 2025/10/24 16:02:38 by strieste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*sort_stock(char **stock);
char	*fill_stock(int fd, char **stock, char **buffer);
size_t	ft_strchr_n(const char *s, int c);

char	*get_next_line(int fd)
{
	static char	*stock;
	char		*line;
	char		*buffer;

	if (!stock)
		stock = ft_strdup("");
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	stock = fill_stock(fd, &stock, &buffer);
	free(buffer);
	if (!stock)
	{
		free(stock);
		stock = NULL;
		return (NULL);
	}
	line = sort_stock(&stock);
	if (!line)
		return (NULL);
	return (line);
}

char	*sort_stock(char **stock)
{
	char	*line;
	char	*temp;
	ssize_t	count;

	count = 0;
	temp = *stock;
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
	*stock = ft_substr(temp, count, ft_strlen(temp));
	free(temp);
	if (*stock == ((char) '\0') || !*stock)
	{
		free(*stock);
		*stock = NULL;
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
		temp = *stock;
		*stock = ft_strjoin(*stock, *buffer);
		free(temp);
		if (!*stock)
			return (NULL);
		if (ft_strchr_n(*stock, '\n'))
			break ;
	}
	return (*stock);
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
//  int	main(void)
//  {
//  	int	fd;

//  	fd = open("README.md", O_RDONLY);
//  	printf("[%s]", get_next_line(fd));
//  	printf("---------------------\n");
//  	printf("[%s]", get_next_line(fd));
//  	printf("---------------------\n");
//  	printf("[%s]", get_next_line(fd));
//  	printf("---------------------\n");
//  	printf("[%s]", get_next_line(fd));
//  	printf("---------------------\n");
//  	printf("[%s]", get_next_line(fd));
//  	printf("---------------------\n");
//  	printf("[%s]", get_next_line(fd));
//  	printf("---------------------\n");
//  	printf("[%s]", get_next_line(fd));
//  	printf("---------------------\n");
//  	printf("[%s]", get_next_line(fd));
//  	printf("---------------------\n");
//  	printf("[%s]", get_next_line(fd));
//  	printf("---------------------\n");
//  	printf("[%s]", get_next_line(fd));
//  	printf("---------------------\n");
//  	printf("[%s]", get_next_line(fd));
//  	printf("---------------------\n");
//  	printf("[%s]", get_next_line(fd));
//  	printf("---------------------\n");
//  	printf("[%s]", get_next_line(fd));
//  	printf("---------------------\n");
//  	printf("[%s]", get_next_line(fd));
//  	printf("---------------------\n");
//  	printf("[%s]", get_next_line(fd));
//  	printf("---------------------\n");
//  	printf("[%s]", get_next_line(fd));
//  	printf("---------------------\n");
//  	printf("[%s]", get_next_line(fd));
//  	printf("---------------------\n");
//  	printf("[%s]", get_next_line(fd));
//  	printf("---------------------\n");
//  	printf("[%s]", get_next_line(fd));

//  	close(fd);
//  	return (0);
//  }

// char	*get_next_line(int fd)
// {
// 	static char *stock;
// 	char *temp;
// 	char *buffer;
// 	size_t count;
// 	ssize_t state_fd;

// 	count = 0;
// 	state_fd = 1;
// 	if (!stock)
// 		stock = ft_strdup("");
// 	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
// 	if (!buffer)
// 		return (NULL);
// 	while (state_fd > 0)
// 	{
// 		state_fd = read(fd, buffer, BUFFER_SIZE);
// 		if (state_fd <= 0)
// 			return (NULL);
// 		if (state_fd < BUFFER_SIZE)
// 		{
// 			buffer = ft_substr(buffer, 0, state_fd);
// 			return (ft_strjoin(stock, buffer));
// 		}
// 		buffer[BUFFER_SIZE + 1] = '\0';
// 		stock = ft_strjoin(stock, buffer);
// 		if (!stock)
// 			return (NULL);
// 		while (stock[count] && stock[count] != '\n')
// 			count++;
// 		if (stock[count] == '\n')
// 		{
// 			buffer = ft_substr(stock, 0, count + 1);
// 			temp = ft_substr(stock, count + 1, ft_strlen(stock));
// 			free(stock);
// 			stock = temp;
// 			break ;
// 		}
// 	}
// 	return (buffer);
// }
