/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhwang <yuhwang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 10:53:20 by yuhwang           #+#    #+#             */
/*   Updated: 2022/04/24 04:40:00 by yuhwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "minilibx_mms/mlx.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	main(int argc, char **argv)
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_data	image;

	if (!argv || !argc)
		return (0);
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "mlx 42");
	image.img = mlx_new_image(mlx_ptr, 500, 500);
	image.addr = mlx_get_data_addr(image.img, &image.bits_per_pixel, &image.line_length, &image.endian);
	for (int i = 0; i < 400; i++)
	{
		for (int j = 0; j < 400; j++)
			mlx_pixel_put(mlx_ptr, win_ptr, i, j, 0x00FFFFFF);
	}
	my_mlx_pixel_put(&image, 200, 300, 0x00FFFFFF);
	mlx_put_image_to_window(mlx_ptr, win_ptr, image.img, 0, 0);
	mlx_loop(mlx_ptr);
	if (!win_ptr)
		return (0);
	return (0);
}
