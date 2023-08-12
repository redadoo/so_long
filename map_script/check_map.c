/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evocatur <evocatur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 14:41:42 by evocatur          #+#    #+#             */
/*   Updated: 2023/08/12 17:15:06 by evocatur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static	int	check_rectangular(t_game game)
{
	int		i;
	int		len;
	char	**map;

	i = 0;
	map = game.map.matrix;
	while (map[i])
	{
		if (i == game.map.height - 1)
		{
			if ((strlen(map[i])) != strlen(map[0]) - 1)
				return (0);
		}
		else
		{
			if (strlen(map[i]) != strlen(map[0]))
				return (0);
		}
		i++;
	}
	return (1);
}

/* check if map inside t_game struct have no error*/
void	check(t_game game)
{
	char	**map;
	int		i;
	int		j;

	map = game.map.matrix;
	i = game.map.height;
	j = game.map.width;
	if (i > j || !map || i == 0 || j == 0 || check_rectangular(game) == 0)
		ft_close_e(game, 1, "map size");
	i = 0;
	j = 0;
	check_env('P', game);
	check_env('E', game);
	check_env('C', game);
	while (i < game.map.height)
	{
		while (j < game.map.width)
		{
			check_wall(map[i][j], i, j, game);
			j++;
		}
		j = 0;
		i++;
	}
}

void	check_wall(char c, int i, int j, t_game game)
{
	if (((i == 0) || (i == game.map.height - 1)) && (j < game.map.width - 1))
	{
		if (c != '1')
			null_error("the map is not surrounded by walls", &game);
	}
	if ((j == 0) || (j == game.map.width - 2))
	{
		if (c != '1')
			null_error("the map is not surrounded by walls", &game);
	}
	if (c != '1' && c != '0' && c != 'P' && c != 'X' && c != 'C'
		&& c != 'E' && c != '\n' && c != 0)
	{
		null_error("the map have strange element", &game);
	}
}

void	check_env(char c, t_game game)
{
	int		i;
	int		j;
	int		count;
	char	**map;

	map = game.map.matrix;
	i = 0;
	j = 0;
	count = 0;
	while (i < game.map.height)
	{
		while (j < game.map.width)
		{
			if (map[i][j] == c)
				count++;
			j++;
		}
		j = 0;
		i++;
	}
	if (count < 1)
		null_error("Error missing 1 exit or 1 coin or 1 start", &game);
	if (count > 1 && c == 'P')
		null_error("too many players", &game);
}

int	check_extension(char *file)
{
	int		count;
	char	*tmp;

	count = 4;
	tmp = (char *)ft_strstr(file, ".ber");
	if (tmp == NULL)
		return (1);
	while (count)
	{
		tmp++;
		count--;
	}
	if ((int)*tmp != 0)
		return (1);
	count = open(file, O_RDONLY);
	if (count == -1)
		return (1);
	close(count);
	return (0);
}
