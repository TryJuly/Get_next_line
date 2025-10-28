/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strieste <strieste@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 08:20:52 by strieste          #+#    #+#             */
/*   Updated: 2025/10/28 09:46:03 by strieste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	int		fd;
	char	*str;

	fd = open("longfile.txt", O_RDONLY);
	str = get_next_line(fd);
	while (str != NULL)
	{
		printf("[%s]", str);
		free(str);
		str = get_next_line(fd);
	}
	close(fd);
	return (0);
}
