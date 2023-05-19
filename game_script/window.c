/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evocatur <evocatur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 14:34:49 by evocatur          #+#    #+#             */
/*   Updated: 2023/05/19 16:46:25 by evocatur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/* create new window */
t_screen	ft_new_window(t_game game, int widht, int height, char *name)
{
	t_screen	window;

	widht *= IMG_SIZE;
	height *= IMG_SIZE;
	window.reference = mlx_new_window(game.mlx, widht + IMG_SIZE / 2, height, name);
	window.size.x = widht;
	window.size.y = height;
	return (window);
}
