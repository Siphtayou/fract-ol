/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agilles <agilles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 15:49:08 by agilles           #+#    #+#             */
/*   Updated: 2024/03/19 19:06:57 by agilles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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

int	closed(int keycode, t_data *data)
{
	if (keycode == 65307)
	{
		mlx_destroy_image(data->mlx, data->img);
		mlx_destroy_window(data->mlx, data->mlx_win);
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
	exit (0);
}


int	main(void)
{
	t_data	data;
	t_cord	z;
	t_cord	c;

	int		i;
	int		j;
	int		k;
	int		max_it;
	int		color;

	max_it = 42;
	data.mlx = mlx_init();
	data.mlx_win = mlx_new_window(data.mlx, WIDTH, HEIGHT, "Hello world!");
	data.img = mlx_new_image(data.mlx, WIDTH, HEIGHT);
	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel, &data.line_length,
								&data.endian);
	i = -1;
	while(++i <= WIDTH)
	{
		j = -1;
		while (++j <= HEIGHT)
		{
			z.x = 0.0;
			z.y = 0.0;

			c.x = scale_min(i, -2, 2);
			c.y = scale_min(j, 2, -2);
			k = 0;
			while (k < max_it)
			{
				z = mand_suit(sqrt_comp(z), c);
				if ((z.x * z.x) + (z.y * z.y) > 4)
				{
					color = trgb(0, 255, 255, 255);
					k = max_it;
				}
				k++;
			}
			if (k == max_it)
				color = trgb(0, 255, 255, 255);
			else
				color = scale_min(k, BLACK, WHITE);
			my_mlx_pixel_put(&data, i, j, color);
		}
	}
	mlx_put_image_to_window(data.mlx, data.mlx_win, data.img, 0, 0);
	mlx_hook(data.mlx_win, 2, 1L<<0, &closed, &data);
	mlx_loop(data.mlx);
}
