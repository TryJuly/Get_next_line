/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strieste <strieste@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 09:50:20 by strieste          #+#    #+#             */
/*   Updated: 2025/10/28 10:41:39 by strieste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*fill_stock(int fd, char *stock);
size_t	newline(char *stock);
char	*clean_stock(char *stock);
char	*extract_line(char *stock);

char	*get_next_line(int fd)
{
	static char	*stock[1024];
	char		*final_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stock[fd] = fill_stock(fd, stock[fd]);
	if (!stock[fd])
		return (NULL);
	final_line = extract_line(stock[fd]);
	stock[fd] = clean_stock(stock[fd]);
	if (!final_line && stock[fd])
	{
		free(stock[fd]);
		return (NULL);
	}
	return (final_line);
}

char	*fill_stock(int fd, char *stock)
{
	char	*buff;
	char	*temp;
	ssize_t	bytes_read;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	bytes_read = 1;
	while (bytes_read > 0 && !newline(stock))
	{
		bytes_read = read(fd, buff, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free(buff);
			free(stock);
			return (NULL);
		}
		buff[bytes_read] = '\0';
		temp = ft_strjoin(stock, buff);
		free(stock);
		stock = temp;
	}
	free(buff);
	return (stock);
}

char	*extract_line(char *stock)
{
	char	*line;
	size_t	count;

	if (!stock || !*stock)
		return (NULL);
	count = 0;
	while (stock[count] && stock[count] != '\n')
		count++;
	if (stock[count] == '\n')
		count++;
	line = ft_substr(stock, 0, count);
	return (line);
}

char	*clean_stock(char *stock)
{
	char	*stock_clean;
	size_t	count;

	if (!stock)
		return (NULL);
	count = 0;
	while (stock[count] && stock[count] != '\n')
		count++;
	if (!stock[count])
	{
		free(stock);
		return (NULL);
	}
	count++;
	stock_clean = ft_substr(stock, count, ft_strlen(stock) - count);
	free(stock);
	if (stock_clean && *stock_clean == '\0')
	{
		free(stock_clean);
		return (NULL);
	}
	return (stock_clean);
}

size_t	newline(char *stock)
{
	size_t	count;

	if (!stock)
		return (0);
	count = 0;
	while (stock[count])
	{
		if (stock[count] == '\n')
			return (1);
		count++;
	}
	return (0);
}
