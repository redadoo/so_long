/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evocatur <evocatur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 15:10:35 by evocatur          #+#    #+#             */
/*   Updated: 2023/05/20 15:28:33 by evocatur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_update(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	update_hud(game);
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
	move_player(game,keycode);
	return (0);
}

void	update_coin(t_game *game)
{
  char arr[5][25] = {MONEY0, MONEY1, MONEY2, MONEY3, MONEY4};
}