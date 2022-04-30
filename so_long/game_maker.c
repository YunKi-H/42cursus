/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_maker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhwang <yuhwang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 15:01:59 by yuhwang           #+#    #+#             */
/*   Updated: 2022/04/30 15:06:36 by yuhwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "so_long.h"
#include "minilibx_mms/mlx.h"

t_game	*game_init(const char *file)
{
	t_game	*game;

	game = (t_game *)malloc(sizeof(t_game));
	game->mlx = mlx_init();
	game->map = map_init(file);
	game->img = img_init(game->mlx);
	game->win = mlx_new_window(game->mlx, (game->map->width - 1) * 40, \
		game->map->height * 40, "so_long");
	map_draw(game);
	game->walk_cnt = 0;
	game->player = get_player(game->map);
	return (game);
}

t_coor	*get_player(t_map *map)
{
	t_coor	*player;
	size_t	x;
	size_t	y;

	player = (t_coor *)malloc(sizeof(t_coor));
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (map->map[y][x] == 'P')
			{
				player->x = x;
				player->y = y;
				break ;
			}
			x += 1;
		}
		y += 1;
	}
	return (player);
}

t_img	*img_init(void *mlx)
{
	t_img	*img;
	int		w;
	int		h;

	img = (t_img *)malloc(sizeof(t_img));
	img->coin = mlx_xpm_file_to_image(mlx, "./img/coin.xpm", &w, &h);
	img->exit = mlx_xpm_file_to_image(mlx, "./img/exit.xpm", &w, &h);
	img->player = mlx_xpm_file_to_image(mlx, "./img/player.xpm", &w, &h);
	img->road = mlx_xpm_file_to_image(mlx, "./img/road.xpm", &w, &h);
	img->wall = mlx_xpm_file_to_image(mlx, "./img/wall.xpm", &w, &h);
	return (img);
}

void	map_draw(t_game *game)
{
	size_t	height;
	size_t	width;

	height = 0;
	while (height < game->map->height)
	{
		width = 0;
		while (width < game->map->width)
		{
			ctoimg(game, width, height);
			width += 1;
		}
		height += 1;
	}
}

void	ctoimg(t_game *game, size_t width, size_t height)
{
	if (game->map->map[height][width] == 'C')
		mlx_put_image_to_window(game->mlx, game->win, game->img->coin, \
			width * 40, height * 40);
	if (game->map->map[height][width] == 'E')
		mlx_put_image_to_window(game->mlx, game->win, game->img->exit, \
			width * 40, height * 40);
	if (game->map->map[height][width] == 'P')
		mlx_put_image_to_window(game->mlx, game->win, game->img->player, \
			width * 40, height * 40);
	if (game->map->map[height][width] == '0')
		mlx_put_image_to_window(game->mlx, game->win, game->img->road, \
			width * 40, height * 40);
	if (game->map->map[height][width] == '1')
		mlx_put_image_to_window(game->mlx, game->win, game->img->wall, \
			width * 40, height * 40);
}
