/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evocatur <evocatur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 15:08:26 by evocatur          #+#    #+#             */
/*   Updated: 2023/05/19 18:49:22 by evocatur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void set_hud(t_game game)
{
	mlx_string_put(game.mlx, game.window.reference,
		15, game.window.size.y + 20, 0xccccff, "step:");
	mlx_string_put(game.mlx, game.window.reference,
		65, game.window.size.y + 20, 0xccccff, "0");
}
