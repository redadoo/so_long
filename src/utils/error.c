/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edoardo <edoardo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 14:42:29 by evocatur          #+#    #+#             */
/*   Updated: 2024/04/13 14:53:21 by edoardo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/so_long.h"

void	null_error(char *message, void *param)
{
	ft_printf("\033[0;31m" " Error\n %s\n" "\033[0m", message);
	//ft_close(param, 0, NULL);
}

void	free_coin(t_coin *coin)
{
	t_coin	*tmp;

	if (!coin)
		return ;
	while (coin != NULL)
	{
		tmp = coin;
		coin = coin->next;
		tmp->sprite.img = NULL;
		tmp->sprite.b_img = NULL;
		tmp->next = NULL;
		if (tmp != NULL)
			free(tmp);
	}
	if (coin != NULL)
		safe_free(coin);
}

int	ft_close(t_game *game, char* error_message)
{
	if (error_message != NULL)
		ft_printf("%s\n", error_message);
	free_matrix(game->map.matrix);
	free_coin(game->env.coin.next);
	safe_free(game->back.b_img);
	safe_free(game->back.img);
	safe_free(game->mlx);
	exit(0);
}