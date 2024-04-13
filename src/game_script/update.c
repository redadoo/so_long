/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edoardo <edoardo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 15:10:35 by evocatur          #+#    #+#             */
/*   Updated: 2024/04/12 17:00:39 by edoardo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/so_long.h"

int	ft_update(t_game *game)
{
	check_collide(game);
 	update_hud(game);
	if (game->env.exit.open == true)
		(void)compare_vector(game->player.pos, game->env.exit.pos, 0, game);
	update_coin(game);
	if (game->env.Ncoin == game->player.collected_coin)
	{
		put_sprite(game, game->env.exit.sprite.b_img, game->env.exit.pos);
		game->env.exit.open = true;
	}
	return (0);
}

int	key_hook(int keycode, t_game *game)
{
	if (keycode == EXIT)
		ft_close(game,NULL);
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
			if (compare_vector(tmp->pos, g->player.pos, 1, g) && tmp->exist)
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
			(void)compare_vector(tmp1->pos, g->player.pos, 0, g);
			tmp1 = tmp1->next;
		}
	}
}

int compare_vector(t_vector2_int v1, t_vector2_int v2, int flag, t_game *game)
{
	int	res;

	res = compare_vector2_int(v1,v2);
	if (res && flag == 1)
		ft_close(game,NULL);
	return (res);
}