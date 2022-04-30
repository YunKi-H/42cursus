/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhwang <yuhwang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 14:45:30 by yuhwang           #+#    #+#             */
/*   Updated: 2022/04/30 14:49:59 by yuhwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "so_long.h"

int	key_press(int key_code, t_game *game)
{
	if (key_code == KEY_W)
		key_w(game);
	if (key_code == KEY_A)
		key_a(game);
	if (key_code == KEY_S)
		key_s(game);
	if (key_code == KEY_D)
		key_d(game);
	if (key_code == KEY_ESC)
		exit_game(game);
	return (0);
}

void	key_w(t_game *game)
{
	int	x;
	int	y;

	x = game->player->x;
	y = game->player->y;
	if (game->map->map[y - 1][x] == 'C')
		game->map->coin_count -= 1;
	if (game->map->map[y - 1][x] == 'E' && !game->map->coin_count)
	{
		printf("YOU WIN!");
		exit_game(game);
	}
	else if (game->map->map[y - 1][x] != '1' && game->map->map[y - 1][x] != 'E')
	{
		game->map->map[y - 1][x] = 'P';
		game->map->map[y][x] = '0';
		game->player->y -= 1;
		game->walk_cnt += 1;
		printf("YOU MOVE %zu TIMES\n", game->walk_cnt);
		map_draw(game);
	}
}

void	key_a(t_game *game)
{
	int	x;
	int	y;

	x = game->player->x;
	y = game->player->y;
	if (game->map->map[y][x - 1] == 'C')
		game->map->coin_count -= 1;
	if (game->map->map[y][x - 1] == 'E' && !game->map->coin_count)
	{
		printf("YOU WIN!");
		exit_game(game);
	}
	else if (game->map->map[y][x - 1] != '1' && game->map->map[y][x - 1] != 'E')
	{
		game->map->map[y][x - 1] = 'P';
		game->map->map[y][x] = '0';
		game->player->x -= 1;
		game->walk_cnt += 1;
		printf("YOU MOVE %zu TIMES\n", game->walk_cnt);
		map_draw(game);
	}
}

void	key_s(t_game *game)
{
	int	x;
	int	y;

	x = game->player->x;
	y = game->player->y;
	if (game->map->map[y + 1][x] == 'C')
		game->map->coin_count -= 1;
	if (game->map->map[y + 1][x] == 'E' && !game->map->coin_count)
	{
		printf("YOU WIN!");
		exit_game(game);
	}
	else if (game->map->map[y + 1][x] != '1' && game->map->map[y + 1][x] != 'E')
	{
		game->map->map[y + 1][x] = 'P';
		game->map->map[y][x] = '0';
		game->player->y += 1;
		game->walk_cnt += 1;
		printf("YOU MOVE %zu TIMES\n", game->walk_cnt);
		map_draw(game);
	}
}

void	key_d(t_game *game)
{
	int	x;
	int	y;

	x = game->player->x;
	y = game->player->y;
	if (game->map->map[y][x + 1] == 'C')
		game->map->coin_count -= 1;
	if (game->map->map[y][x + 1] == 'E' && !game->map->coin_count)
	{
		printf("YOU WIN!");
		exit_game(game);
	}
	else if (game->map->map[y][x + 1] != '1' && game->map->map[y][x + 1] != 'E')
	{
		game->map->map[y][x + 1] = 'P';
		game->map->map[y][x] = '0';
		game->player->x += 1;
		game->walk_cnt += 1;
		printf("YOU MOVE %zu TIMES\n", game->walk_cnt);
		map_draw(game);
	}
}
