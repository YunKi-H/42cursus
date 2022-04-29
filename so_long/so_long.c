/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhwang <yuhwang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 10:53:20 by yuhwang           #+#    #+#             */
/*   Updated: 2022/04/29 21:37:20 by yuhwang          ###   ########.fr       */
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
	t_map	*map;

	if (argc < 2)
	{
		write(1, "USAGE : \"./so_long [MAP.ber]\"\n", 31);
		exit(0);
	}
	map = map_init();
	map_get_info(argv[1], map);
	map_read_file(argv[1], map);
	//print map
	size_t	i = 0;
	while (i < map->height)
		printf("%s", map->map[i++]);

	return (0);
}

t_map	*map_init(void)
{
	t_map	*map;

	map = (t_map *)malloc(sizeof(t_map));
	map->map = NULL;
	map->width = 0;
	map->height = 0;
	map->coin_count = 0;
	map->player_count = 0;
	map->exit_count = 0;
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
	if (map->player_count != 1)
		print_error(5, NO_START_POINT);
	if (map->exit_count != 1)
		print_error(5, NO_EXIT);
	close(fd);
}

void	isvalid_extension(const char *file)
{
	char	*tmp;

	tmp = ft_strrchr(file, '.');
	if (!tmp)
		print_error(4, INVALID_FILE);
	if (ft_strncmp(tmp, ".ber", 4))
		print_error(4, INVALID_FILE);
	if (*(tmp + 4))
		print_error(4, INVALID_FILE);
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

void	isvalid_char(char c, t_map *map)
{
	if (c == 'C')
		map->coin_count += 1;
	else if (c == 'P')
		map->player_count += 1;
	else if (c == 'E')
		map->exit_count += 1;
	else if (c != '0' && c != '1')
		print_error(3, "MAP HAS WRONG CHARACTER");
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

int	isvalid_sealed(t_map *map, size_t width, size_t height)
{
	size_t	i;

	i = 0;
	if (!isvalid_edge(map->map[i], width))
		return (0);
	i += 1;
	while (i < height - 1)
	{
		if (!isvalid_mid(map->map[i], width))
			return (0);
		i += 1;
	}
	if (!isvalid_edge(map->map[i], width))
		return (0);
	return (1);
}

int	isvalid_edge(char *line, size_t length)
{
	size_t	i;

	i = 0;
	while (i < length - 1)
	{
		if (line[i] != '1')
			return (0);
		i += 1;
	}
	return (1);
}

int	isvalid_mid(char *line, size_t length)
{
	return (line[0] == '1' && line[length - 2] == '1');
}

void	print_error(int errnum, const char *msg)
{
	write(2, "Error\n",6);
	write(2, msg, ft_strlen(msg));
	exit(errnum);
}
