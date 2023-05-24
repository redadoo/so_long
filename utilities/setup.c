/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evocatur <evocatur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 14:35:51 by evocatur          #+#    #+#             */
/*   Updated: 2023/05/24 14:35:01 by evocatur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../so_long.h"

void init_game(t_game game)
{
	check(game);
	set_hud(game);
	spawn_map(game);
}

void *give_and_put_sprite(t_sprite sprite, t_game *game, char *path, t_vector2 pos)
{
	mlx_put_image_to_window(game->mlx, game->window.reference, sprite.b_img, pos.x * IMG_SIZE, pos.y * IMG_SIZE);
	sprite.img = mlx_xpm_file_to_image(game->mlx, path, &sprite.size.x, &sprite.size.y);
	mlx_put_image_to_window(game->mlx, game->window.reference, sprite.img, pos.x * IMG_SIZE ,pos.y * IMG_SIZE);
	return (sprite.img);
}