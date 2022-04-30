/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhwang <yuhwang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 14:51:32 by yuhwang           #+#    #+#             */
/*   Updated: 2022/04/30 14:53:02 by yuhwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "../libft/libft.h"

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

void	isvalid_char(char c, t_map *map)
{
	if (c == 'C')
		map->coin_count += 1;
	else if (c == 'E')
		map->exit_count += 1;
	else if (c == 'P')
		map->player_count += 1;
	else if (c != '0' && c != '1')
		print_error(3, "MAP HAS WRONG CHARACTER");
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
