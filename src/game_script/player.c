/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edoardo <edoardo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 15:18:22 by evocatur          #+#    #+#             */
/*   Updated: 2024/04/13 15:25:29 by edoardo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/so_long.h"

t_player	init_player(t_game *g)
{
	t_player	p;

	g->player.pos.x = 0;
	g->player.pos.y = 0;
	p.sprite.img = give_sprite(g, PLAYER_SPRITE);
	p.sprite.b_img = give_sprite(g, GRASS);
	p.collected_coin = 0;
	while (g->player.pos.y < g->map.height)
	{
		while (g->map.matrix[g->player.pos.y][g->player.pos.x] != '\0')
		{
			if (g->map.matrix[g->player.pos.y][g->player.pos.x] == 'P')
				p.pos = g->player.pos;
			g->player.pos.x++;
		}
		g->player.pos.x = 0;
		g->player.pos.y++;
	}
	mlx_put_image_to_window(g->mlx, g->window.reference,
		p.sprite.img, p.pos.x * IMG_SIZE, p.pos.y * IMG_SIZE);
	return (p);
}

t_vector2_int	move_player(t_game *game, int dir)
{
	t_vector2_int	oldpos;

	oldpos = game->player.pos;
	if (check_move(game, UP) && dir == UP)
	{
		game->player.pos.y--;
		move_sprite(game, oldpos);
	}
	else if (check_move(game, DOWN) && dir == DOWN)
	{
		game->player.pos.y++;
		move_sprite(game, oldpos);
	}
	else if (check_move(game, RIGHT) && dir == RIGHT)
	{
		game->player.pos.x++;
		move_sprite(game, oldpos);
	}
	else if (check_move(game, LEFT) && dir == LEFT)
	{
		game->player.pos.x--;
		move_sprite(game, oldpos);
	}
	return (game->player.pos);
}

int	check_move(t_game *game, int dir)
{
	int	x;
	int	y;

	x = game->player.pos.x;
	y = game->player.pos.y;
	if (dir == UP)
		y--;
	else if (dir == DOWN)
		y++;
	else if (dir == RIGHT)
		x++;
	else if (dir == LEFT)
		x--;
	if (game->map.matrix[y][x] == '1')
		return (0);
	if (!game->env.exit.open && game->map.matrix[y][x] == 'E')
		return (0);
	return (1);
}

void	move_sprite(t_game *game, t_vector2_int oldpos)
{
	game->step += 1;
	mlx_put_image_to_window(game->mlx, game->window.reference,
		game->player.sprite.b_img, oldpos.x * IMG_SIZE, oldpos.y * IMG_SIZE);
	mlx_put_image_to_window(game->mlx, game->window.reference,
		game->player.sprite.b_img,game->player.pos.x * IMG_SIZE, game->player.pos.y * IMG_SIZE);
	mlx_put_image_to_window(game->mlx, game->window.reference,
		game->player.sprite.img, game->player.pos.x * IMG_SIZE,
		game->player.pos.y * IMG_SIZE);
}
