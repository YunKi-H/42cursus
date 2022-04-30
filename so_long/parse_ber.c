/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_ber.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhwang <yuhwang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 14:54:21 by yuhwang           #+#    #+#             */
/*   Updated: 2022/04/30 15:15:21 by yuhwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <limits.h>
#include "so_long.h"
#include "./libft/libft.h"

t_map	*map_init(const char *file)
{
	t_map	*map;

	map = (t_map *)malloc(sizeof(t_map));
	map->map = NULL;
	map->width = 0;
	map->height = 0;
	map->coin_count = 0;
	map->exit_count = 0;
	map->player_count = 0;
	map_get_info(file, map);
	map_read_file(file, map);
	return (map);
}

void	map_get_info(const char *file, t_map *map)
{
	int	fd;

	isvalid_extension(file);
	fd = open(file, O_RDONLY);
	if (fd < 0 || fd > OPEN_MAX)
		print_error(2, INVALID_FD);
	while (read_line_f(fd, map))
		;
	if (!map->coin_count)
		print_error(5, NO_COLLECTIBLES);
	if (map->exit_count != 1)
		print_error(5, NO_EXIT);
	if (map->player_count != 1)
		print_error(5, NO_START_POINT);
	close(fd);
}

int	read_line_f(int fd, t_map *map)
{
	char	*buf;
	size_t	len;
	int		i;

	buf = get_next_line(fd);
	if (!buf)
		return (0);
	len = ft_strlen(buf);
	if (map->width && map->width != len)
		print_error(4, IS_NOT_SQUARE);
	map->width = len;
	map->height += 1;
	i = 0;
	while (buf[i] != '\n' && buf[i])
	{
		isvalid_char(buf[i], map);
		i += 1;
	}
	free(buf);
	return (1);
}

void	map_read_file(const char *file, t_map *map)
{
	int		fd;
	size_t	i;

	map->map = (char **)malloc(sizeof(char *) * map->height);
	if (!map->map)
		print_error(1, MALLOC_FAILED);
	fd = open(file, O_RDONLY);
	if (fd < 0 || fd > OPEN_MAX)
		print_error(2, INVALID_FD);
	i = 0;
	while (i < map->height)
	{
		map->map[i] = get_next_line(fd);
		i += 1;
	}
	if (!isvalid_sealed(map, map->width, map->height))
		print_error(4, IS_NOT_SEALED);
}
