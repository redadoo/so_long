/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evocatur <evocatur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 15:10:35 by evocatur          #+#    #+#             */
/*   Updated: 2023/05/24 15:29:22 by evocatur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_update(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	check_collide(game);
	update_hud(game);
	update_coin(game);
	if (game->env.Ncoin == game->player.collected_coin)
	{
		put_sprite(game, game->env.exit.sprite.b_img, game->env.exit.pos);
		game->env.exit.open = true;
	}
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
	char		*arr[5] = {MONEY0, MONEY1, MONEY2, MONEY3, MONEY4};
	t_coin		*tmp;
	static int	frame;
	static int	index;

	frame++;
	if (frame == ANIMATION_FRAMES)
	{
		if (game->env.coin.next != NULL)
		{
			tmp = game->env.coin.next;
			while (tmp != NULL)
			{
				if (tmp->exist == 1)
					tmp->sprite.img = give_and_put_sprite(tmp->sprite,game,arr[index],tmp->pos);
				tmp = tmp->next;
			}
			index++;
		}	
	}
	else if (frame == ANIMATION_FRAMES * 4)
		frame = 0;
	if (index == 4)
		index = 0;
}

void	check_collide(t_game *game)
{
	t_coin		*tmp;

	if (game->env.exit.open == true)
	{
		if (game->env.exit.pos.x == game->player.pos.x && game->env.exit.pos.y == game->player.pos.y)
		{
			ft_close(&game);
		}
	}
	if (game->env.coin.next != NULL)
	{
		tmp = game->env.coin.next;
		while (tmp != NULL)
		{
			if (tmp->pos.x == game->player.pos.x && tmp->pos.y == game->player.pos.y && tmp->exist == 1)
			{
				tmp->exist = 0;
				game->player.collected_coin++;
			}
			tmp = tmp->next;
		}
	}	
}
