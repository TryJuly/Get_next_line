/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strieste <strieste@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 13:42:50 by strieste          #+#    #+#             */
/*   Updated: 2025/10/22 15:02:43 by strieste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char		*fill_stock(int fd, char *stock, char *buffer);
static char		*get_str(char *stock);
static char		*ft_back_start(char *stock);
//static void	ft_buff_clean(char *buffer);

char	*get_next_line(int fd)
{
	static char	*stock;
	char		*final_str;
	char		*buffer;

	if (!stock)
		stock = ft_strdup("");
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	stock = fill_stock(fd, stock, buffer);
	if (!stock || stock[0] == '\0')
	{
		free(buffer);
		return (NULL);
	}
	free(buffer);
	buffer = NULL;
	final_str = get_str(stock);
	if (!final_str)
		return (NULL);
	stock = ft_back_start(stock);
	if (!stock)
		return (NULL);
	return (final_str);
}
// static void	ft_buff_clean(char *buffer)
// {
// 	size_t	count;

// 	count = 0;
// 	while (count < BUFFER_SIZE)
// 		buffer[count++] = '\0';
// }

static char	*ft_back_start(char *stock)
{
	char	*back_stock;
	size_t	count;

	count = 0;
	while (stock[count] && stock[count] != '\n')
		count++;
	count++;
	back_stock = ft_substr(stock, count, ft_strlen(stock));
	if (!back_stock)
		return (NULL);
	free(stock);
	stock = back_stock;
	return (stock);
}

static char	*get_str(char *stock)
{
	char	*str_back;
	size_t	count;

	count = 0;
	while (stock[count] && stock[count] != '\n')
		count++;
	str_back = malloc((count + 1) * sizeof(char));
	if (!str_back)
		return (NULL);
	str_back = ft_substr(stock, 0, count + 1);
	return (str_back);
}

static char	*fill_stock(int fd, char *stock, char *buffer)
{
	ssize_t	state_fd;
	size_t	count;

	state_fd = 1;
	count = 0;
	//ft_buff_clean(buffer);
	while (state_fd > 0)
	{
		state_fd = read(fd, buffer, BUFFER_SIZE);
		if (state_fd == -1)
			return (NULL);
		else if (state_fd < BUFFER_SIZE || BUFFER_SIZE < 3)
			buffer[state_fd] = '\0';
		else
			buffer[BUFFER_SIZE + 1] = '\0';
		stock = ft_strjoin(stock, buffer);
		if (!stock || stock == NULL)
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
	printf("[%s]", get_next_line(fd));
	printf("---------------------\n");
	printf("[%s]", get_next_line(fd));
	printf("---------------------\n");
	printf("[%s]", get_next_line(fd));
	printf("---------------------\n");
	printf("[%s]", get_next_line(fd));
	printf("---------------------\n");
	printf("[%s]", get_next_line(fd));
	printf("---------------------\n");
	printf("[%s]", get_next_line(fd));
	printf("---------------------\n");
	printf("[%s]", get_next_line(fd));
	printf("---------------------\n");
	printf("[%s]", get_next_line(fd));
	printf("---------------------\n");
	printf("[%s]", get_next_line(fd));
	printf("---------------------\n");
	printf("[%s]", get_next_line(fd));
	printf("---------------------\n");
	printf("[%s]", get_next_line(fd));
	printf("---------------------\n");
	printf("[%s]", get_next_line(fd));
	printf("---------------------\n");
	printf("[%s]", get_next_line(fd));
	printf("---------------------\n");
	printf("[%s]", get_next_line(fd));
	printf("---------------------\n");
	printf("[%s]", get_next_line(fd));
	printf("---------------------\n");
	printf("[%s]", get_next_line(fd));
	printf("---------------------\n");
	printf("[%s]", get_next_line(fd));
	printf("---------------------\n");
	printf("[%s]", get_next_line(fd));
	printf("---------------------\n");
	printf("[%s]", get_next_line(fd));

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