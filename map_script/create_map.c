/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evocatur <evocatur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 15:12:00 by evocatur          #+#    #+#             */
/*   Updated: 2023/05/19 16:00:50 by evocatur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	spawn_map(t_game game)
{
	char		**map;
	t_sprite	test;

	test.img = mlx_xpm_file_to_image(game.mlx, PLAYER_SPRITE, &test.size.x, &test.size.y);
	mlx_put_image_to_window(game.mlx, game.window.reference, test.img, 0, 0);
}
