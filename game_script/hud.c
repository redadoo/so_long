/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evocatur <evocatur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 15:08:26 by evocatur          #+#    #+#             */
/*   Updated: 2023/05/26 14:28:19 by evocatur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	set_hud(t_game game)
{
	mlx_string_put(game.mlx, game.window.reference,
		15, game.window.size.y + 20, 0xccccff, "step:");
	mlx_string_put(game.mlx, game.window.reference,
		65, game.window.size.y + 20, 0xccccff, "0");
}

void	update_hud(t_game *game)
{
	char	*s;

	s = ft_itoa(game->step);
	mlx_put_image_to_window(game->mlx, game->window.reference,
		game->back.img, 60, game->window.size.y + 20);
	mlx_string_put(game->mlx, game->window.reference,
		65, game->window.size.y + 20, 0xccccff, s);
	free(s);
}
