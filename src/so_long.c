/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edoardo <edoardo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 13:53:06 by evocatur          #+#    #+#             */
/*   Updated: 2024/04/13 01:24:56 by edoardo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/so_long.h"

void set_null(t_game *game)
{
	game->map.matrix = NULL;
	game->mlx = NULL;
	game->window.reference = NULL;
	game->back.img = NULL;
	game->back.b_img = NULL;
}

void	run_game(t_game *game)
{
 	game->window = ft_new_window(game,
			game->map.width, game->map.height, "so_long");
	game->step = 0;
	game->back.img = mlx_xpm_file_to_image(game->mlx, BACK,
			&game->back.size.x, &game->back.size.y);
	init_game(game);
	game->player = init_player(game);
	game->env = spawn_env(game);
	mlx_loop_hook(game->mlx, ft_update, game);
	mlx_key_hook(game->window.reference, *key_hook, game);
	mlx_hook(game->window.reference, 17, 1L << 0, *ft_close, game);
	mlx_loop(game->mlx); 
}

int	main(int argc, char**argv)
{
	t_game	game;

	if (argc != 2 || check_extension(argv[1]) == 1)
		ft_close(&game, "Error on given file");
	set_null(&game);
	game.mlx = mlx_init();
	game.env.coin.next = NULL;
	game.map = readmap(&game, argv[1]);
	check(&game);
	run_game(&game);
}
