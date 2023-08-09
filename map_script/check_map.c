/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evocatur <evocatur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 14:41:42 by evocatur          #+#    #+#             */
/*   Updated: 2023/08/09 10:55:32 by evocatur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/* check if map inside t_game struct have no error*/
void	check(t_game game)
{
	char	**map;
	int		i;
	int		j;

	map = game.map.matrix;
	i = game.map.height;
	j = game.map.width;
	if (i > j || !map || i == 0 || j == 0)
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
