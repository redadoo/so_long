/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evocatur <evocatur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 15:10:35 by evocatur          #+#    #+#             */
/*   Updated: 2023/05/19 17:21:07 by evocatur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_update(void *param)
{
	return (0);
}

int	key_hook(int keycode, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (keycode == EXIT)
	{
		ft_close(param);
	}
	if (keycode == UP)
	{
		move_player(game,UP);
	}
	return (0);
}
