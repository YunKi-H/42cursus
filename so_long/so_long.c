/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhwang <yuhwang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 10:53:20 by yuhwang           #+#    #+#             */
/*   Updated: 2022/04/27 16:40:53 by yuhwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include "so_long.h"
#include "../libft/libft.h"
#include "minilibx_mms/mlx.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == KEY_ESC)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	return (0);
}

int	exit_hook()
{
	exit(0);
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	main(int argc, char **argv)
{
	// int	color;
	// t_data	image;
	// t_vars	vars;

	if (argc < 2)
	{
		write(1, "USAGE : \"./so_long [MAP.ber]\"\n", 31);
		exit(0);
	}
	int		fd;
	// t_map	map;
	printf("%s\n", argv[1]);
	fd = open(argv[1], O_RDONLY);
	printf("fd = %d\n", fd);
	// char temp[10];
	// temp[9] = 0;
	// read(fd, temp, 9);
	// printf("%s\n", temp);
	// write(3, "test\n", 5);
	while (1)
	{
		char	*buf;
		size_t	len;

		buf = get_next_line(fd);
		printf("%s", buf);
		if (!buf)
			break ;
		len = ft_strlen(buf);
		len++;
	}

	// int	img_width = 1080;
	// int	img_height = 720;

	// vars.mlx = mlx_init();
	// vars.win = mlx_new_window(vars.mlx, img_width, img_height, "mlx 42");
	// // image.img = mlx_new_image(vars.mlx, img_width, img_height);
	// image.img = mlx_xpm_file_to_image(vars.mlx, "./resource/pacman_down.xpm", &img_width, &img_height);
	// image.addr = mlx_get_data_addr(image.img, &image.bits_per_pixel, &image.line_length, &image.endian);
	// // for (int i = 0; i < img_height - 1; i++)
	// // {
	// // 	for (int j = 0; j < img_width - 1; j++)
	// // 	{
	// // 		double r = (double)(img_width - j) / (img_height - 1);
	// // 		double g = (double)(i) / (img_height - 1);
	// // 		double b = 1;
	// // 		color = create_trgb(0, 255.999 * r, 255.999 * g, 255.999 * b);
	// // 		my_mlx_pixel_put(&image, j, i, color);
	// // 	}
	// // }
	// for (int i = 0; i < img_height - 1; i += 50)
	// {
	// 	for (int j = 0; j < img_width - 1; j += 50)
	// 	{
	// 		printf("i = %d, j = %d\n", i, j);
	// 		mlx_put_image_to_window(vars.mlx, vars.win, image.img, j, i);
	// 	}
	// }
	// // mlx_put_image_to_window(vars.mlx, vars.win, image.img, 0, 0);
	// // mlx_put_image_to_window(vars.mlx, vars.win, image.img, 50, 0);
	// // mlx_put_image_to_window(vars.mlx, vars.win, image.img, 0, 50);
	// // mlx_put_image_to_window(vars.mlx, vars.win, image.img, 50, 50);
	// mlx_key_hook(vars.win, key_hook, &vars);
	// mlx_hook(vars.win, 17, 0, exit_hook, 0);
	// mlx_loop(vars.mlx);
	return (0);
}

void	print_error(const char *msg)
{
	write(2, "Error\n",6);
	write(2, msg, ft_strlen(msg));
	exit(1);
}