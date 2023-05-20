/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evocatur <evocatur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 14:35:51 by evocatur          #+#    #+#             */
/*   Updated: 2023/05/20 14:40:37 by evocatur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../so_long.h"

void init_game(t_game game)
{
    //t_game games;
    game.map = readmap(&game, argv[1]);
    check(game);
    game.back.img = mlx_xpm_file_to_image(game.mlx, BACK, &game.back.size.x, &game.back.size.y);
	game.step = 0;
    set_hud(game);
    spawn_map(game);
    game.player = init_player(game);
	spawn_env(game);

}