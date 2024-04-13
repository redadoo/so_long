/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edoardo <edoardo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 13:54:23 by evocatur          #+#    #+#             */
/*   Updated: 2024/04/13 00:11:33 by edoardo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#ifdef __linux__
	# include "../mlx_linux/mlx.h"
	#define UP 119
	#define LEFT 97
	#define DOWN 115
	#define RIGHT 100
	#define EXIT 65307
#elif __APPLE__
	# include "mlx.h"
	#define UP 13
	#define LEFT 0
	#define DOWN 1
	#define RIGHT 2
	#define EXIT 53
#endif

# include "libft/libft.h"
# include "vector/vector.h"
# include <stdint.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
 
#define PLAYER_SPRITE "Sprites/player/player_0.xpm"
#define SLIME "Sprites/env/slime.xpm"
#define DOOR0 "Sprites/env/Door0.xpm"
#define DOOR1 "Sprites/env/Door1.xpm"
#define WALL "Sprites/wall/wall.xpm"
#define GRASS "Sprites/title/grass.xpm"
#define MONEY0 "Sprites/env/sprite_0.xpm"
#define MONEY1 "Sprites/env/sprite_1.xpm"
#define MONEY2 "Sprites/env/sprite_2.xpm"
#define MONEY3 "Sprites/env/sprite_3.xpm"
#define MONEY4 "Sprites/env/sprite_4.xpm"
#define BACK "Sprites/env/backstring.xpm"
#define IMG_SIZE 32
#define ANIMATION_FRAMES 12

typedef struct s_window {
	void			*reference;
	t_vector2_int	size;
}	t_screen;

typedef struct s_map {
	char		**matrix;
	int			height;
	int			width;
}	t_map;

typedef struct s_sprite {
	void			*img;
	void			*b_img;
	t_vector2_int	size;
}	t_sprite;

typedef struct s_player{
	int				collected_coin;
	t_vector2_int	pos;
	t_sprite		sprite;
}	t_player;

typedef struct s_coin{
	int				exist;
	t_vector2_int	pos;
	t_sprite		sprite;
	struct s_coin	*next;
}	t_coin;

typedef struct s_enemy{
	bool			exist;
	t_vector2_int	pos;
	t_sprite		sprite;
	struct s_enemy	*next;
}	t_enemy;

typedef struct s_exit{
	bool			open;
	t_vector2_int	pos;
	t_sprite		sprite;
}	t_exit;

typedef struct s_env{
	int			Ncoin;
	int			Nenemy;
	char		*a[4];
	t_coin		coin;
	t_enemy		enemy;
	t_exit		exit;
}	t_env;

typedef struct s_game{
	void			*reference;
	void			*mlx;
	int				step;
	t_player		player;
	t_screen		window;
	t_sprite		back;	
	t_map			map;
	t_env			env;
}	t_game;

void			run_game(t_game *game);
t_map			readmap(void *param, char *file);
t_screen		ft_new_window(t_game *game, int widht, int height, char *name);
void			null_error(char *message, void *param);
void			check(t_game *game);
void			check_env(char c, t_game *game);
void			check_wall(char c, int i, int j,t_game *game);
int				ft_close(t_game *game, char *error_message);
void			set_hud(t_game *game);
int				ft_update(t_game *game);
int				key_hook(int keycode, t_game *game);
void			spawn_map(t_game *game);
void			printmatrix(char **matrix);
t_player		init_player(t_game *game);
t_vector2_int	move_player(t_game *game, int dir);
int				check_move(t_game *game, int dir);
void			move_sprite(t_game *game, t_vector2_int newpos);
void			update_hud(t_game *game);
void			init_game(t_game *game);
t_env			spawn_env(t_game *game);
void			update_coin(t_game *game);
t_env			add_coin(t_game *game, int x, int y, t_env env);
void			*set_put(t_sprite sprite, t_game *game, char *path, t_vector2_int pos);
void			check_collide(t_game *game);
t_exit			set_exit(t_game *game, int x, int y);
void			put_sprite(t_game *game, void *img, t_vector2_int pos);
t_env			add_enemy(t_game *game, int x, int y, t_env env);
void			free_coin(t_coin *coin);
void			*give_sprite(t_game *game, char*p);
void			*give_and_put_sprite_f(t_sprite sp, t_game *game, char *p, t_vector2_int pos);
void			build_array(char *arr[]);
int				check_extension(char *file);
int				compare(const char *X, const char *Y);
const char* 	ft_strstr(const char* X, const char* Y);
void			free_map(char **map);
int 			compare_vector(t_vector2_int v1, t_vector2_int v2, int flag, t_game *game);
#endif