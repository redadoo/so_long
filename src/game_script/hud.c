/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edoardo <edoardo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 15:08:26 by evocatur          #+#    #+#             */
/*   Updated: 2024/04/12 16:38:42 by edoardo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/so_long.h"

void	set_hud(t_game *game)
{
	mlx_string_put(game->mlx, game->window.reference,
		15, game->window.size.y + 20, 0xccccff, "step:");
	mlx_string_put(game->mlx, game->window.reference,
		65, game->window.size.y + 20, 0xccccff, "0");
}

void	update_hud(t_game *game)
{
	char	*s;

	s = ft_itoa(game->step);
	mlx_put_image_to_window(game->mlx, game->window.reference,
		game->back.img, 60, game->window.size.y + 5);
	mlx_string_put(game->mlx, game->window.reference,
		65, game->window.size.y + 20, 0xccccff, s);
	safe_free(s);
}

void	build_array(char *arr[])
{
	arr[0] = MONEY0;
	arr[1] = MONEY1;
	arr[2] = MONEY2;
	arr[3] = MONEY3;
	arr[4] = MONEY4;
}
