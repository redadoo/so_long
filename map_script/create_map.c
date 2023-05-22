/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evocatur <evocatur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 15:12:00 by evocatur          #+#    #+#             */
/*   Updated: 2023/05/20 17:37:57 by evocatur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	spawn_map(t_game game)
{
	int			x;
	int			y;
	char		**map;
	t_sprite	test;

	x = 0;
	y = 0;
	test.img = mlx_xpm_file_to_image(game.mlx,GRASS,&test.size.x,&test.size.y);
	test.b_img = mlx_xpm_file_to_image(game.mlx,WALL,&test.size.x,&test.size.y);
	while (game.map.matrix[y])
	{
		while (game.map.matrix[y][x] != '\0')
		{
			if (game.map.matrix[y][x] == '0' || game.map.matrix[y][x] == 'P' || game.map.matrix[y][x] == 'C'|| game.map.matrix[y][x] == 'E')
				mlx_put_image_to_window(game.mlx,game.window.reference,test.img,x * 32,y * 32);
			if (game.map.matrix[y][x] == '1')
				mlx_put_image_to_window(game.mlx,game.window.reference,test.b_img,x * 32,y * 32);
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
	t_coin		coin;
	t_coin		*last;

	x = 0;
	y = 0;
	env.coin.sprite.img = mlx_xpm_file_to_image(game.mlx, MONEY0, &env.coin.sprite.size.x, &env.coin.sprite.size.y);
	env.coin.next = NULL;
	while (y < game.map.height)
	{
		while (x < game.map.width)
		{
			if (game.map.matrix[y][x] == 'C')
					env = add_coin(game,x,y,env);
			x++;
		}
		x = 0;
		y++;
	}
	return (env);
}

t_env	add_coin(t_game game, int x, int y, t_env env)
{
	t_coin *new;
	t_coin *last;

 	new = malloc(sizeof(t_coin));
	new->sprite.img = mlx_xpm_file_to_image(game.mlx, MONEY0, &new->sprite.size.x, &new->sprite.size.y);
	new->pos.x = x;
	new->pos.y = y; 
	mlx_put_image_to_window(game.mlx, game.window.reference, new->sprite.img, x * IMG_SIZE, y * IMG_SIZE);
	new->next = NULL;
	if (!env.coin.next)
	{
		env.coin.next = new;
	}
	else
	{
		last = env.coin.next;
		while (last->next != NULL)
			last = last->next;
		last->next = new;
	}
	return (env);
}