/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evocatur <evocatur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 15:12:00 by evocatur          #+#    #+#             */
/*   Updated: 2023/05/19 17:02:29 by evocatur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	spawn_map(t_game game)
{
	int			x;
	int			y;
	char		**map;
	t_sprite	test;

	x = 0;
	y = 0;
	test.img = mlx_xpm_file_to_image(game.mlx,GRASS,&test.size.x,&test.size.y);
	test.b_img = mlx_xpm_file_to_image(game.mlx,WALL,&test.size.x,&test.size.y);
	while (game.map.matrix[y])
	{
		while (game.map.matrix[y][x] != '\0')
		{
			if (game.map.matrix[y][x] == '0' || game.map.matrix[y][x] == 'P' || game.map.matrix[y][x] == 'C'|| game.map.matrix[y][x] == 'E')
				mlx_put_image_to_window(game.mlx,game.window.reference,test.img,x * 32,y * 32);
			if (game.map.matrix[y][x] == '1')
				mlx_put_image_to_window(game.mlx,game.window.reference,test.b_img,x * 32,y * 32);
			x++;
		}	
		x = 0;
		y++;
	}
	
}
