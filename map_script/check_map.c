/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evocatur <evocatur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 14:41:42 by evocatur          #+#    #+#             */
/*   Updated: 2023/05/19 14:26:52 by evocatur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void check(t_game game)
{
	char **map;
	int i;
	int j;

	map = game.map.matrix;
	i = game.map.height;
	j = game.map.width;
	if (i > j || !map)
		ft_close(&game);
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

void check_wall(char c, int i, int j,t_game game)
{
	if (((i == 0) || (i == game.map.height - 1)) && (j < game.map.width - 1))
	{
		if (c != '1')
			null_error("the map is not surrounded by walls",&game);
	}
	if ((j == 0) || (j == game.map.width - 2))
	{
		if (c != '1')
			null_error("the map is not surrounded by walls",&game);
	}
}

void check_env(char c,t_game game)
{
	int 	i;
	int 	j;
	int		count;
	char 	**map;

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
		null_error("The map does not contain at least 1 exit, 1 collectible and 1 starting location.", &game);
}