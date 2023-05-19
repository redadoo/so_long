/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evocatur <evocatur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 13:54:23 by evocatur          #+#    #+#             */
/*   Updated: 2023/05/19 14:55:22 by evocatur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "gnl/get_next_line.h"
# include "ft_libft/libft.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <mlx.h>

#ifdef __linux__

#endif

#ifdef __APPLE__
	#define UP = 13
	#define LEFT = 0
	#define DOWN = 1
	#define RIGHT = 2
#endif

typedef struct s_vector
{
	int	x;
	int	y;
}	t_vector2;

typedef struct s_window {
	void		*reference;
	t_vector2	size;
}	t_screen;

typedef struct s_map {
	char		**matrix;
	int			height;
	int			width;
}	t_map;

typedef struct s_game{
	void			*reference;
	void			*mlx;
	t_screen		window;
	t_map			map;
	int				step;
}	t_game;


void		set_game(t_game game, int argc, char **argv);
t_map		readmap(void *param, char *file);
t_screen	ft_new_window(t_game game, int widht, int height, char *name);
void		null_error(char *message, void *param);
void		check(t_game game);
void		check_env(char c,t_game game);
void		check_wall(char c, int i, int j,t_game game);
int			ft_close(void *param);
void		set_hud(t_game game);
int			ft_update(void *param);
void		check_ber(char *name);
int			key_hook(int keycode,void *param);


#endif