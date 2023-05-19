/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evocatur <evocatur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 14:42:29 by evocatur          #+#    #+#             */
/*   Updated: 2023/05/19 16:11:42 by evocatur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../so_long.h"

void	null_error(char *message, void *param)
{
	t_game		*game;

	game = (t_game *)param;
	printf("\033[0;31m" " Error\n %s\n" "\033[0m", message);
	ft_close(param);
}

int	ft_close(void *param)
{	
	exit(0);
}

void	check_ber(char *name)
{
	if (ft_strnstr(name, ".ber", 9) != NULL)
	{
		printf("\033[0;31m" " Error\n \n" "\033[0m");
		exit(0);
	}
}
