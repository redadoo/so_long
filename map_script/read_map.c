/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evocatur <evocatur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 14:01:35 by evocatur          #+#    #+#             */
/*   Updated: 2023/05/19 17:00:39 by evocatur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	file_linecount(char *file)
{
	char	c;	
	int		fd;	
	int		linecount;
	int		readcount;

	fd = open(file, O_RDONLY);
	if (!fd)
		return (-1);
	linecount = 1;
	while (true)
	{
		readcount = read(fd, &c, 1);
		if (readcount == 0)
			break ;
		if (readcount < 0)
			return (-1);
		if (c == '\n')
			linecount++;
	}
	close(fd);
	return (linecount);
}

/* read a file and return the map inside it*/
t_map	readmap(void *param, char *file)
{
	int				i;
	int				fd;
	int				len;
	char			**map;
	t_map			game_map;

	map = (char **)ft_calloc((sizeof(char *)), file_linecount(file) + 1);
	if (map == NULL)
		return (game_map);
	fd = open(file, O_RDONLY);
	i = 0;
	while (i < file_linecount(file))
	{
		map[i] = get_next_line(fd);
		len = ft_strlen(map[i]);
		i++;
	}
	game_map.height = file_linecount(file);
	game_map.width = ft_strlen(map[0]);
	game_map.matrix = map;
	close(fd);
	return (game_map);
}

/* print the received matrix*/
void	printmatrix(char **matrix)
{
	char	*str;

	if (!matrix)
		return ;
	while (*matrix)
	{
		str = *matrix;
		while (*str)
		{
			ft_printf("\033[0m");
			if (*str == 'P')
				ft_printf("\x1b[32m");
			if (*str == 'C')
				ft_printf("\x1b[33m");
			if (*str == 'E')
				ft_printf("\x1b[34m");
			ft_printf("%c", *str);
			str++;
		}
		matrix++;
	}
	printf("\n");
	return ;
}
