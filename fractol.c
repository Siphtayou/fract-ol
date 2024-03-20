/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agilles <agilles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 15:49:08 by agilles           #+#    #+#             */
/*   Updated: 2024/03/20 19:12:58 by agilles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_fractol *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	closed(int keycode, t_fractol *ftl)
{
	if (keycode == 65307)
	{
		mlx_destroy_image(ftl->mlx, ftl->img);
		mlx_destroy_window(ftl->mlx, ftl->mlx_win);
		mlx_destroy_display(ftl->mlx);
		free(ftl->mlx);
		free(ftl);
		exit (0);
	}
	else
		return (1);
}

int	mouse_zoom(int keycode, int x, int y, t_fractol *ftl)
{
	(void)x;
	(void)y;
	if (keycode == 4)
	{
		ftl->zoom *= 1.05;
		if (ftl->max_it > 40)
			ftl->max_it -= 10;
	}
	else if (keycode == 5)
	{
		ftl->zoom *= 0.95;
		ftl->max_it += 10;
	}
	else
	{
		ftl->zoom = 1;
		ftl->max_it = 150;
		ftl->shift_x = 0;
		ftl->shift_y = 0;
	}
	fractol_render(*ftl);
	return (0);
}

t_fractol	*fractol_init(t_fractol *fractol)
{
	fractol->i = -1;
	fractol->j = -1;
	fractol->k = 0;
	fractol->max_it = 150;
	fractol->zoom = 1.0;
	fractol->shift_x = 0.0;
	fractol->shift_y = 0.0;
	return (fractol);
}

int	main(void)
{
	t_fractol	*ftl;

	ftl = malloc(sizeof(t_fractol));
	ftl = fractol_init(ftl);
	ftl->mlx = mlx_init();
	ftl->mlx_win = mlx_new_window(ftl->mlx, WIDTH, HEIGHT, "Hello world!");
	ftl->img = mlx_new_image(ftl->mlx, WIDTH, HEIGHT);
	ftl->addr = mlx_get_data_addr(ftl->img, &ftl->bits_per_pixel, &ftl->line_length,
								&ftl->endian);
	fractol_render(*ftl);
	event_init(ftl);
	mlx_loop(ftl->mlx);
}
