/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhwang <yuhwang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 10:53:24 by yuhwang           #+#    #+#             */
/*   Updated: 2022/04/24 17:56:33 by yuhwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define KEY_ESC 53
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define IS_NOT_SEALED "MAP IS NOT SEALED"
# define IS_NOT_SQUARE "MAP IS NOT SQUARE"
# define NO_EXIT "MAP HAS NO EXIT"
# define NO_COLLECTIBLES "MAP HAS NO COLLETIBLES"
# define NO_START_POINT "MAP HAS NO START POINT"
# define MALLOC_FAILED "MEMORY ALLOCATION FAILED"

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
	size_t	collectibles;
	t_coor	exit;
	t_coor	player;
}	t_map;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
}	t_vars;

typedef struct s_data
{
	void 	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

#endif
