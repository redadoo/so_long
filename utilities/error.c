/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evocatur <evocatur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 14:42:29 by evocatur          #+#    #+#             */
/*   Updated: 2023/05/24 16:45:01 by evocatur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../so_long.h"

void	null_error(char *message, void *param)
{
	t_game		*game;

	game = (t_game *)param;
	ft_printf("\033[0;31m" " Error\n %s\n" "\033[0m", message);
	ft_close(param);
}

int	ft_close(void *param)
{	
	t_game		*game;
	char		**map;
	char		*line;

	game = (t_game *)param;
	map = game->map.matrix;
	while (*map)
	{
		line = *map;
		free(line);
		map++;
	}
	exit(0);
}

int	ft_close_f(t_game *game)
{
	char	**map;
	char	*line;
	t_enemy *tmp;
	t_enemy *last;
	t_coin	*tmp1;
	t_coin	*last1;

	map = game->map.matrix;
	printf("\n test");
	while (*map)
	{
		line = *map;
		free(line);
		map++;
	}
	exit(0);
}

int	ft_close_e(t_game game)
{
	char **map;
	char *line;

	map = game.map.matrix;
	while (*map)
	{
		line = *map;
		free(line);
		map++;
	}
	exit(0);
}

void	check_ber(char *name)
{
	if (ft_strnstr(name, ".ber", 9) != NULL)
	{
		ft_printf("\033[0;31m" " Error\n \n" "\033[0m");
		exit(0);
	}
}
