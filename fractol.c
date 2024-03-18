/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agilles <agilles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 15:49:08 by agilles           #+#    #+#             */
/*   Updated: 2024/03/18 19:11:20 by agilles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}


int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	int		i;
	int		j;
	int		color;

	i = 0;
	j = 0;
	int	minous, plous = 0;
	color = 0x00FF0000;
	plous = 0;
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	while(i <= 1920)
	{
		while (j <= 1080)
		{
			if (minous != 255 && plous == 0)
				minous += 1;
			else if (minous == 255)
			{
				plous = 1;
				minous -= 1;
			}
			else if (minous != 0 && plous == 1)
				minous -= 1;
			else if (minous == 0)
			{
				minous += 1;
				plous = 0;
			}
			color = trgb(0, 255, minous, 0);
			my_mlx_pixel_put(&img, i, j, color);
			j++;
		}
		j = 0;
		i++;
	}
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}



