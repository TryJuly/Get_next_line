/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strieste <strieste@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 13:58:45 by strieste          #+#    #+#             */
/*   Updated: 2025/10/24 13:59:51 by strieste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
	if (count > 0)
	{
		p_str = malloc((count + 1) * sizeof(char));
		if (!p_str)
		{
			free(p_str);
			return (NULL);
		}
		count = 0;
		while (s[count])
		{
			p_str[count] = s[count];
			count++;
		}
		p_str[count] = '\0';
		return (p_str);
	}
	return (NULL);
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
	if (count > 0)
	{
		p_strjoint = malloc((count + 1) * sizeof(char));
		if (!p_strjoint)
			return (NULL);
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
	return (NULL);
}

// static char	*ft_error(char *p_substr)
// {
// 	free(p_substr);
// 	return (NULL);
// }

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*p_substr;
	size_t	count;
	size_t	len_src;

	if (!s)
		return (NULL);
	len_src = ft_strlen(s);
	if (start >= len_src)
		return (ft_strdup(""));
	count = 0;
	if (start + len > len_src)
		len = len_src - start;
	p_substr = malloc((len + 1) * sizeof(char));
	if (!p_substr)
		return (NULL);
	while (count < len && s[start + count])
	{
		p_substr[count] = s[start + count];
		count++;
	}
	p_substr[count] = '\0';
	return (p_substr);
}
