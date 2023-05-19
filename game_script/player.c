/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evocatur <evocatur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 15:18:22 by evocatur          #+#    #+#             */
/*   Updated: 2023/05/19 18:35:12 by evocatur         ###   ########.fr       */
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
	player.sprite.b_img = mlx_xpm_file_to_image(game.mlx, GRASS, &player.sprite.size.x, &player.sprite.size.y);
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
	t_vector2 oldpos;

	oldpos = game->player.pos;
	if (check_move(game, UP) && dir == UP)
	{
		game->player.pos.y--;
		move_sprite(game,oldpos);
	}
	else if (check_move(game, DOWN) && dir == DOWN)
	{
		game->player.pos.y++;
		move_sprite(game,oldpos);
	}
	else if (check_move(game, RIGHT) && dir == RIGHT)
	{
		game->player.pos.x++;
		move_sprite(game,oldpos);
	}
	else if (check_move(game, LEFT) && dir == LEFT)
	{
		game->player.pos.x--;
		move_sprite(game,oldpos);
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
		y--;
	if (dir == DOWN)
		y++;
	if (dir == RIGHT)
		x++;
	if (dir == LEFT)
		x--;
	if (game->map.matrix[y][x] == '1')
		return (0);
	return (1);
}

void move_sprite(t_game *game,t_vector2 oldpos)
{
	mlx_put_image_to_window(game->mlx, game->window.reference, game->player.sprite.b_img, oldpos.x * IMG_SIZE, oldpos.y  * IMG_SIZE);
	mlx_put_image_to_window(game->mlx, game->window.reference, game->player.sprite.img,  game->player.pos.x * IMG_SIZE, game->player.pos.y * IMG_SIZE);
}
