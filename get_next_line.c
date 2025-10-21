/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strieste <strieste@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 13:42:50 by strieste          #+#    #+#             */
/*   Updated: 2025/10/21 17:37:16 by strieste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*fill_stock(int fd);

char	*get_next_line(int fd)
{
	static char	*stock;

	stock = fill_stock(fd);
	if (!stock)
		return (NULL);
}

char	*fill_stock(int fd)
{
	char	*stock;
	char	*buffer;
	ssize_t	state_fd;
	size_t	count;

	state_fd = 1;
	count = 0;
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	while (state_fd > 0)
	{
		state_fd = read(fd, buffer, BUFFER_SIZE);
		if (state_fd <= 0)
			return (NULL);
		buffer[BUFFER_SIZE + 1] = '\0';
		stock = ft_strjoin(stock, buffer);
		if (!stock)
			return (NULL);
		while (stock[count] && stock[count] != '\n')
			count++;
		if (stock[count] == '\n')
			break ;
	}
	return (stock);
}

int main(void)
{
	int fd;

	fd = open("README.md", O_RDONLY);
	printf("%s", get_next_line(fd));
	printf("---------------------\n");
	printf("%s", get_next_line(fd));
	printf("---------------------\n");
	printf("%s", get_next_line(fd));
	printf("---------------------\n");
	printf("%s", get_next_line(fd));
	printf("---------------------\n");
	printf("%s", get_next_line(fd));
	printf("---------------------\n");
	printf("%s", get_next_line(fd));
	printf("---------------------\n");
	printf("%s", get_next_line(fd));
	printf("---------------------\n");
	printf("%s", get_next_line(fd));
	printf("---------------------\n");
	printf("%s", get_next_line(fd));
	printf("---------------------\n");
	printf("%s", get_next_line(fd));
	printf("---------------------\n");
	printf("%s", get_next_line(fd));
	printf("---------------------\n");
	printf("%s", get_next_line(fd));
	printf("---------------------\n");
	printf("%s", get_next_line(fd));
	printf("---------------------\n");
	printf("[%s]\n", get_next_line(fd));
	printf("---------------------\n");
	printf("[%s]\n", get_next_line(fd));
	printf("---------------------\n");
	printf("[%s]\n", get_next_line(fd));
	printf("---------------------\n");
	printf("[%s]\n", get_next_line(fd));
	printf("---------------------\n");
	printf("[%s]\n", get_next_line(fd));
	printf("---------------------\n");
	printf("[%s]\n", get_next_line(fd));

	close(fd);
	return (0);
}

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