/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evocatur <evocatur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 14:35:51 by evocatur          #+#    #+#             */
/*   Updated: 2023/05/20 15:09:33 by evocatur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../so_long.h"

void init_game(t_game game)
{
	check(game);
	set_hud(game);
	spawn_map(game);
	spawn_env(game);
}