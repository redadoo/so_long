/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evocatur <evocatur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 15:10:35 by evocatur          #+#    #+#             */
/*   Updated: 2023/08/09 10:58:09 by evocatur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_update(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	check_collide(game);
	if (game->env.exit.open == true)
		(void)compare_vector(game->player.pos, game->env.exit.pos, game, 0);
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
		ft_close(param, 0, NULL);
	}
	move_player(game, keycode);
	return (0);
}

void	update_coin(t_game *g)
{
	t_coin		*tmp;
	static int	frame;
	static int	i;

	frame++;
	build_array(g->env.a);
	if (frame == ANIMATION_FRAMES)
	{
		if (g->env.coin.next != NULL)
		{
			tmp = g->env.coin.next;
			while (tmp != NULL)
			{
				if (tmp->exist == 1)
					tmp->sprite.img = set_put(tmp->sprite,
							g, g->env.a[i], tmp->pos);
				tmp = tmp->next;
			}
			i++;
		}
	}
	else if (frame == ANIMATION_FRAMES * 4)
		frame = 0;
	if (i == 4)
		i = 0;
}

void	check_collide(t_game *g)
{
	t_coin		*tmp;
	t_enemy		*tmp1;

	if (g->env.coin.next != NULL)
	{
		tmp = g->env.coin.next;
		while (tmp != NULL)
		{
			if (compare_vector(tmp->pos, g->player.pos, g, 1) && tmp->exist)
			{
				tmp->exist = 0;
				g->player.collected_coin++;
			}
			tmp = tmp->next;
		}
	}
	if (g->env.enemy.next != NULL)
	{
		tmp1 = g->env.enemy.next;
		while (tmp1 != NULL)
		{
			(void)compare_vector(tmp1->pos, g->player.pos, g, 0);
			tmp1 = tmp1->next;
		}
	}
}

int	compare_vector(t_vector2 v1, t_vector2 v2, t_game *game, int i)
{
	if (v1.x == v2.x && v1.y == v2.y)
	{
		if (i == 0)
			ft_close_f(game, 0, NULL);
		else
			return (1);
	}
	return (0);
}
