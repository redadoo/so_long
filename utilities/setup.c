/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evocatur <evocatur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 14:35:51 by evocatur          #+#    #+#             */
/*   Updated: 2023/08/09 10:11:45 by evocatur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	init_game(t_game game)
{
	set_hud(game);
	spawn_map(game);
}

void	*set_put(t_sprite sp, t_game *game, char *p, t_vector2 pos)
{
	mlx_put_image_to_window(game->mlx, game->window.reference,
		sp.b_img, pos.x * IMG_SIZE, pos.y * IMG_SIZE);
	sp.img = mlx_xpm_file_to_image(game->mlx, p, &sp.size.x, &sp.size.y);
	mlx_put_image_to_window(game->mlx, game->window.reference,
		sp.img, pos.x * IMG_SIZE, pos.y * IMG_SIZE);
	return (sp.img);
}

void	put_sprite(t_game *game, void *img, t_vector2 pos)
{
	mlx_put_image_to_window(game->mlx, game->window.reference,
		img, pos.x * IMG_SIZE, pos.y * IMG_SIZE);
}

void	*give_sprite(t_game game, char*p)
{
	t_sprite	sp;

	sp.img = mlx_xpm_file_to_image(game.mlx, p, &sp.size.x, &sp.size.y);
	return (sp.img);
}

void	*give_and_put_sprite_f(t_sprite sp, t_game game, char *p, t_vector2 pos)
{
	sp.img = mlx_xpm_file_to_image(game.mlx, p, &sp.size.x, &sp.size.y);
	mlx_put_image_to_window(game.mlx, game.window.reference,
		sp.img, pos.x * IMG_SIZE, pos.y * IMG_SIZE);
	return (sp.img);
}
