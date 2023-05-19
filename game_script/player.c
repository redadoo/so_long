/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evocatur <evocatur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 15:18:22 by evocatur          #+#    #+#             */
/*   Updated: 2023/05/19 18:19:41 by evocatur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

t_player init_player(t_game game)
{
	int			x;
	int			y;
	t_player    player;

	x = 0;
	y = 0;
	player.sprite.img = mlx_xpm_file_to_image(game.mlx, PLAYER_SPRITE, &player.sprite.size.x, &player.sprite.size.y);
	while (game.map.matrix[y] != '\0')
	{
		while (game.map.matrix[y][x] != '\0')
		{
			if (game.map.matrix[y][x] == 'P')
			{
				mlx_put_image_to_window(game.mlx, game.window.reference, player.sprite.img,x * IMG_SIZE, y * IMG_SIZE);
				player.pos.x = x;
				player.pos.y = y;
				return (player);
			}
			x++;
		}	
		x = 0;
		y++;
	}
	return (player);
}

t_vector2 move_player(t_game *game, int dir)
{
	if (check_move(game, UP) && dir == UP)
	{
		game->player.pos.y--;
		mlx_put_image_to_window(game->mlx, game->window.reference, game->player.sprite.img, game->player.pos.x * IMG_SIZE, game->player.pos.y * IMG_SIZE);
	}
	else if (check_move(game, DOWN) && dir == DOWN)
	{
		game->player.pos.y++;
		mlx_put_image_to_window(game->mlx, game->window.reference, game->player.sprite.img, game->player.pos.x * IMG_SIZE, game->player.pos.y * IMG_SIZE);
	}
	else if (check_move(game, RIGHT) && dir == RIGHT)
	{
		game->player.pos.x++;
		mlx_put_image_to_window(game->mlx, game->window.reference, game->player.sprite.img, game->player.pos.x * IMG_SIZE, game->player.pos.y * IMG_SIZE);
	}
	else if (check_move(game, LEFT) && dir == LEFT)
	{
		game->player.pos.x--;
		mlx_put_image_to_window(game->mlx, game->window.reference, game->player.sprite.img, game->player.pos.x * IMG_SIZE, game->player.pos.y * IMG_SIZE);
	}
	return (game->player.pos);
}

int check_move(t_game *game, int dir)
{
	int x;
	int y;

	x = game->player.pos.x;
	y = game->player.pos.y;

	if (dir == UP)
	{
		y--;
		if (game->map.matrix[y][x] == '1')
			return (0);
	}
	if (dir == DOWN)
	{
		y++;
		if (game->map.matrix[y][x] == '1')
			return (0);
	}
	if (dir == RIGHT)
	{
		x++;
		if (game->map.matrix[y][x] == '1')
			return (0);
	}
	if (dir == LEFT)
	{
		x--;
		if (game->map.matrix[y][x] == '1')
			return (0);
	}
	return (1);
}

int convert(int dir,int num)
{
	if (dir == UP)
		return (num++);
	if (dir == DOWN)
		return (num--);
	if (dir == LEFT)
		return (num++);
	if (dir == RIGHT)
		return (num--);
	return (0);
}
