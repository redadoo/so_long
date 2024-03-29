/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evocatur <evocatur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 13:53:06 by evocatur          #+#    #+#             */
/*   Updated: 2023/08/09 11:03:36 by evocatur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	run_game(t_game game, int argc, char **argv)
{
	if (argc != 2 || check_extension(argv[1]) == 1)
		ft_close_e(game, 1, "file or argc");
	game.env.coin.next = NULL;
	game.map = readmap(&game, argv[1]);
	check(game);
	game.window = ft_new_window(game,
			game.map.width, game.map.height, "so_long");
	game.step = 0;
	game.back.img = mlx_xpm_file_to_image(game.mlx, BACK,
			&game.back.size.x, &game.back.size.y);
	init_game(game);
	game.player = init_player(game);
	game.env = spawn_env(game);
	mlx_key_hook(game.window.reference, *key_hook, &game);
	mlx_loop_hook(game.mlx, ft_update, &game);
	mlx_hook(game.window.reference, 17, 0, *ft_close, &game);
	mlx_loop(game.mlx);
}

int	main(int argc, char**argv)
{
	t_game	game;

	game.mlx = mlx_init();
	run_game(game, argc, argv);
}
