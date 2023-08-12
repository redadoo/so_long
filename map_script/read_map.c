/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evocatur <evocatur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 14:01:35 by evocatur          #+#    #+#             */
/*   Updated: 2023/08/12 16:50:24 by evocatur         ###   ########.fr       */
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
	char			**map;
	t_map			game_map;

	map = ft_calloc((sizeof(char *)), file_linecount(file) + 1);
	if (map == NULL)
		return (game_map);
	fd = open(file, O_RDONLY);
	i = 0;
	while (i < file_linecount(file))
	{
		map[i] = get_next_line(fd);
		if (map[i] == NULL)
		{
			free_map(map);
			ft_close(param, 1, "map error");
		}
		i++;
	}
	game_map.height = file_linecount(file);
	game_map.width = ft_strlen(map[0]);
	game_map.matrix = map;
	close(fd);
	return (game_map);
}

void	free_map(char **map)
{
	int		i;
	char	*line;

	i = 0;
	while (map[i])
	{
		line = map[i];
		if (line)
			free(line);
		i++;
	}
	free(map);
}
