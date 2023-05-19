/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evocatur <evocatur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 14:34:49 by evocatur          #+#    #+#             */
/*   Updated: 2023/05/19 15:05:56 by evocatur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

t_screen	ft_new_window(t_game game, int widht, int height, char *name)
{
	t_screen	window;

	window.reference = mlx_new_window(game.mlx, widht * 32, height * 32, name);
	window.size.x = widht;
	window.size.y = height;
	return (window);
}
