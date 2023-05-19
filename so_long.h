/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evocatur <evocatur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 13:54:23 by evocatur          #+#    #+#             */
/*   Updated: 2023/05/19 18:41:02 by evocatur         ###   ########.fr       */
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
 
#define PLAYER_SPRITE "Sprites/player/player_0.xpm"
#define WALL "Sprites/wall/wall.xpm"
#define GRASS "Sprites/title/grass.xpm"

#define EXIT 53
#define IMG_SIZE 32

#ifdef __linux__
	#define UP 77
	#define LEFT 61
	#define DOWN 73
	#define RIGHT 64
#elif __APPLE__
	#define UP 13
	#define LEFT 0
	#define DOWN 1
	#define RIGHT 2
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

typedef struct s_sprite {
	void		*img;
	void		*b_img;
	t_vector2	size;
}	t_sprite;

typedef struct s_player{
	t_vector2	pos;
	t_sprite	sprite;
}	t_player;

typedef struct s_coin{
	t_vector2		pos;
	t_sprite		sprite;
	struct s_coin	*next;
}	t_coin;

typedef struct s_enemy{
	t_vector2		pos;
	t_sprite		sprite;
	struct s_enemy	*next;
}	t_enemy;

typedef struct s_game{
	void			*reference;
	void			*mlx;
	t_player		player;
	t_screen		window;
	t_enemy			enemys;
	t_coin			coins;
	t_map			map;
	int				step;
}	t_game;

void		run_game(t_game game, int argc, char **argv);
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
void		spawn_map(t_game game);
void		printmatrix(char **matrix);
t_player	init_player(t_game game);
t_vector2	move_player(t_game *game, int dir);
int			check_move(t_game *game, int dir);
void		move_sprite(t_game *game,t_vector2 newpos);
#endif