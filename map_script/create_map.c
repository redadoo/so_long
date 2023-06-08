/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evocatur <evocatur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 15:12:00 by evocatur          #+#    #+#             */
/*   Updated: 2023/06/08 15:56:08 by evocatur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	spawn_map(t_game game)
{
	int			x;
	int			y;
	char		**map;
	t_sprite	s;

	x = 0;
	y = 0;
	s.img = mlx_xpm_file_to_image(game.mlx, GRASS, &s.size.x, &s.size.y);
	s.b_img = mlx_xpm_file_to_image(game.mlx, WALL, &s.size.x, &s.size.y);
	while (game.map.matrix[y])
	{
		while (game.map.matrix[y][x] != '\0')
		{
			if (game.map.matrix[y][x] == '0' || game.map.matrix[y][x] == 'P'
				|| game.map.matrix[y][x] == 'C' || game.map.matrix[y][x] == 'E')
				mlx_put_image_to_window(game.mlx,
					game.window.reference, s.img, x * 32, y * 32);
			if (game.map.matrix[y][x] == '1')
				mlx_put_image_to_window(game.mlx, game.window.reference,
					s.b_img, x * 32, y * 32);
			x++;
		}	
		x = 0;
		y++;
	}
}

t_env	spawn_env(t_game game)
{
	int			x;
	int			y;
	t_env		env;

	x = 0;
	y = 0;
	env.Ncoin = 0;
	env.coin.next = NULL;
	env.enemy.next = NULL;
	while (y < game.map.height)
	{
		while (x < game.map.width)
		{
			if (game.map.matrix[y][x] == 'C')
				env = add_coin(game, x, y, env);
			if (game.map.matrix[y][x] == 'E')
				env.exit = set_exit(game, x, y);
			if (game.map.matrix[y][x] == 'X')
				env = add_enemy(game, x, y, env);
			x++;
		}
		x = 0;
		y++;
	}
	return (env);
}

t_env	add_coin(t_game game, int x, int y, t_env env)
{
	t_coin	*new;
	t_coin	*last;

	new = malloc(sizeof(t_coin));
	if (!new)
		return (env);
	new->sprite.img = give_sprite(game, MONEY0);
	new->sprite.b_img = give_sprite(game, GRASS);
	new->pos.x = x;
	new->pos.y = y;
	mlx_put_image_to_window(game.mlx,
		game.window.reference, new->sprite.img, x * 32, y * 32);
	new->next = NULL;
	new->exist = 1;
	env.Ncoin++;
	if (!env.coin.next)
		env.coin.next = new;
	else
	{
		last = env.coin.next;
		while (last->next != NULL)
			last = last->next;
		last->next = new;
	}
	return (env);
}

t_exit	set_exit(t_game game, int x, int y)
{
	t_exit	exit;

	exit.pos.x = x;
	exit.pos.y = y;
	exit.sprite.img = give_sprite(game, DOOR0);
	exit.sprite.b_img = give_sprite(game, DOOR1);
	mlx_put_image_to_window(game.mlx, game.window.reference,
		exit.sprite.img, x * IMG_SIZE, y * IMG_SIZE);
	exit.open = false;
	return (exit);
}

t_env	add_enemy(t_game game, int x, int y, t_env env)
{
	t_enemy	*new;
	t_enemy	*last;

	new = malloc(sizeof(t_enemy));
	if (!new)
		return (env);
	new->pos.x = x;
	new->pos.y = y;
	new->sprite.b_img = give_and_put_sprite_f(new->sprite,
			game, GRASS, new->pos);
	new->sprite.img = give_and_put_sprite_f(new->sprite, game, SLIME, new->pos);
	new->next = NULL;
	new->exist = 1;
	if (!env.enemy.next)
		env.enemy.next = new;
	else
	{
		last = env.enemy.next;
		while (last->next != NULL)
			last = last->next;
		last->next = new;
	}
	return (env);
}
