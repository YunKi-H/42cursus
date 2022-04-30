/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhwang <yuhwang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 10:53:20 by yuhwang           #+#    #+#             */
/*   Updated: 2022/04/30 15:04:36 by yuhwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <limits.h>
#include "so_long.h"
#include "../libft/libft.h"
#include "minilibx_mms/mlx.h"

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc != 2)
	{
		write(1, "USAGE : \"./so_long [MAP.ber]\"\n", 31);
		exit(0);
	}
	game = game_init(argv[1]);
	mlx_key_hook(game->win, &key_press, game);
	mlx_hook(game->win, KEY_EXIT, 0, &exit_game, game);
	mlx_loop(game->mlx);
	return (0);
}

int	exit_game(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	exit(0);
	return (0);
}

void	print_error(int errnum, const char *msg)
{
	write(2, "Error\n", 6);
	write(2, msg, ft_strlen(msg));
	exit(errnum);
}
