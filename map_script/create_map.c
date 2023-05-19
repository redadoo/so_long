/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evocatur <evocatur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 15:12:00 by evocatur          #+#    #+#             */
/*   Updated: 2023/05/19 14:17:00 by evocatur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void spawn_map(void *param)
{
	char	**map;
	t_game	*game;

	game = (t_game *)param;
	map = game->map.matrix;
	
}