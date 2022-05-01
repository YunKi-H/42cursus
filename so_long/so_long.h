/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhwang <yuhwang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 10:53:24 by yuhwang           #+#    #+#             */
/*   Updated: 2022/05/01 12:45:23 by yuhwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define KEY_EXIT 17
# define KEY_ESC 53
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define INVALID_FILE "HAVE TO PUT [.ber] FILE\n"
# define INVALID_FD "FAIL TO OPEN FILE\n"
# define IS_NOT_SEALED "MAP IS NOT SEALED\n"
# define IS_NOT_SQUARE "MAP IS NOT SQUARE\n"
# define NO_EXIT "MAP MUST HAVE ONE EXIT\n"
# define NO_COLLECTIBLES "MAP MUST HAVE AT LEAST ONE COLLETIBLES\n"
# define NO_START_POINT "MAP MUST HAVE ONE START POINT\n"
# define MALLOC_FAILED "MEMORY ALLOCATION FAILED\n"

# include <stddef.h>
# include "get_next_line.h"

typedef struct s_coor
{
	int	x;
	int	y;
}	t_coor;

typedef struct s_map
{
	char	**map;
	size_t	width;
	size_t	height;
	size_t	coin_count;
	size_t	exit_count;
	size_t	player_count;
}	t_map;

typedef struct s_img
{
	void	*coin;
	void	*exit;
	void	*player;
	void	*road;
	void	*wall;
}	t_img;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	t_map	*map;
	t_img	*img;
	size_t	walk_cnt;
	t_coor	*player;
}	t_game;

int		key_press(int key_code, t_game *game);
void	key_w(t_game *game);
void	key_a(t_game *game);
void	key_s(t_game *game);
void	key_d(t_game *game);

t_coor	*get_player(t_map *map);
t_game	*game_init(const char *file);
t_img	*img_init(void *mlx);
void	map_draw(t_game *game);
void	ctoimg(t_game *game, size_t width, size_t height);

t_map	*map_init(const char *file);
void	map_get_info(const char *file, t_map *map);
int		read_line_f(int fd, t_map *map);
void	map_read_file(const char *file, t_map *map);

void	isvalid_extension(const char *file);
void	isvalid_char(char c, t_map *map);
int		isvalid_sealed(t_map *map, size_t width, size_t height);
int		isvalid_edge(char *line, size_t length);
int		isvalid_mid(char *line, size_t length);

void	print_error(int errnum, const char *msg);
int		exit_game(t_game *game);

#endif
