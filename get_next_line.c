/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strieste <strieste@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 13:42:50 by strieste          #+#    #+#             */
/*   Updated: 2025/10/20 14:10:20 by strieste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *s);
size_t	ft_strlen(const char *str);
size_t	ft_strlcat(char *dest, const char *src, size_t n);


char	*get_next_line(int fd)
{
	ssize_t		read_fd;
	size_t		count;
	char		buff[BUFFER_SIZE];
	static char	*stock_fd;
	char		*final_str;

	if (!fd)
		return (NULL);
	read_fd = 1;
	count = 0;
	final_str = NULL;
	buff[0] = '\0';
	while (buff[count] != '\n' && read_fd > 0)
	{
		read_fd = read(fd, buff, BUFFER_SIZE);
		while (buff[count] && buff[count] != '\n' && count < BUFFER_SIZE)
			count++;
		final_str = ft_strjoin(final_str, buff);
		if (!final_str)
			return (NULL);
		count = 0;
	}
	return (final_str);
}

int	main(void)
{
	int	fd;

	fd = open("README.md", O_RDONLY);
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));

	printf("%d\n", fd);
	return (0);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	count;
	size_t	count_s;
	char	*p_strjoint;

	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	count = (ft_strlen(s1) + ft_strlen(s2));
	p_strjoint = malloc((count + 1) * sizeof(char));
	if (!p_strjoint)
		return ((void *) 0);
	count = 0;
	count_s = 0;
	while (s1[count])
		p_strjoint[count++] = s1[count_s++];
	count_s = 0;
	while (s2[count_s])
		p_strjoint[count++] = s2[count_s++];
	p_strjoint[count] = '\0';
	return (p_strjoint);
}

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*ft_strdup(const char *s)
{
	char	*p_str;
	size_t	count;

	count = ft_strlen(s);
	p_str = malloc((count + 1) * sizeof(char));
	if (!p_str)
		return ((void *) 0);
	count = 0;
	while (s[count])
	{
		p_str[count] = s[count];
		count++;
	}
	p_str[count] = '\0';
	return (p_str);
}

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t	save;
	size_t	count;
	size_t	count_dest;
	size_t	len_dest;
	size_t	len_src;

	len_src = ft_strlen(src);
	if (n == 0)
		return (len_src);
	save = ft_strlen(dest);
	len_dest = save;
	count = 0;
	if (n <= len_dest)
		return (n + len_src);
	count_dest = len_dest;
	while (count < (n - 1) && src[count] && count_dest < (n - 1))
	{
		dest[count_dest] = src[count];
		count_dest++;
		count++;
	}
	dest[count_dest] = '\0';
	return (save + len_src);
}