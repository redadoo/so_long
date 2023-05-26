/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evocatur <evocatur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 14:42:29 by evocatur          #+#    #+#             */
/*   Updated: 2023/05/26 14:32:36 by evocatur         ###   ########.fr       */
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
	t_coin		*tmp;
	t_game		*game;
	char		**map;
	char		*line;

	game = (t_game *)param;
	tmp = game->env.coin.next;
	map = game->map.matrix;
	printf("\n test   c");
	while (*map)
	{
		line = *map;
		free(line);
		map++;
	}
	free(game->map.matrix);
	free_coin(game->env.coin.next);
	exit(0);
}

int	ft_close_f(t_game *game)
{
	char	**map;
	char	*line;

	map = game->map.matrix;
	while (*map)
	{
		line = *map;
		free(line);
		map++;
	}
	free(game->map.matrix);
	free_coin(game->env.coin.next);
	exit(0);
}

int	ft_close_e(t_game game)
{
	char	**map;
	char	*line;

	map = game.map.matrix;
	while (*map)
	{
		line = *map;
		free(line);
		map++;
	}
	free(game.map.matrix);
	free_coin(game.env.coin.next);
	exit(0);
}

void	free_coin(t_coin *coin)
{
	t_coin	*tmp;

	if (coin == NULL)
		return ;
	while (coin != NULL)
	{
		tmp = coin;
		coin = coin->next;
		tmp->sprite.img = NULL;
		tmp->sprite.b_img = NULL;
		tmp->next = NULL;
		tmp->pos.x = 0;
		tmp->pos.y = 0;
		free(tmp);
	}
	free(coin);
}
