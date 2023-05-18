/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evocatur <evocatur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 13:53:06 by evocatur          #+#    #+#             */
/*   Updated: 2023/05/18 14:01:50 by evocatur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


void	set_game(t_game game, int argc, char **argv)
{
	if (argc == 2)
	{
		game.map = 
		
	}
}

int	main(int argc, char **argv)
{
	t_game	game;

	game.mlx = mlx_init();
	set_game(game, argc, argv);
}
