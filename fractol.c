/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agilles <agilles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 15:49:08 by agilles           #+#    #+#             */
/*   Updated: 2024/03/22 18:25:03 by agilles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <time.h>

void	my_mlx_pixel_put(t_fractol *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

t_fractol	*fractol_init(t_fractol *fractol)
{
	if (COLOR_MODE)
		fractol->color_start = BLACK;
	else
		fractol->color_start = trgb(0, rand() % 255, rand() % 255, rand() % 255);
	fractol->i = -1;
	fractol->j = -1;
	fractol->k = 0;
	fractol->max_it = 100;
	fractol->zoom = 1.0;
	fractol->shift_x = 0.0;
	fractol->shift_y = 0.0;
	// fractol->color_end = RED;
	fractol->color_end = trgb(0, rand() % 255, rand() % 255, rand() % 255);
	return (fractol);
}

int	ftl_error(char *error_msg)
{
	ft_printf("%s\n", error_msg);
	return (1);
}

int	main(int ac, char **av)
{
	(void)ac;
	if ((ft_strcmp(av[1], "Mandelbrot") && ft_strcmp(av[1], "Julia")
		&& ft_strcmp(av[1], "Burning Ship")) || ac == 1 || ac == 3 || ac > 4)
		return (ftl_error("Chien"));
	srand(time(NULL));
	t_fractol	*ftl;
	ftl = malloc(sizeof(t_fractol));
	ftl = fractol_init(ftl);
	ftl->mlx = mlx_init();
	ftl->mlx_win = mlx_new_window(ftl->mlx, WIDTH, HEIGHT, "Hello world!");
	ftl->img = mlx_new_image(ftl->mlx, WIDTH, HEIGHT);
	ftl->addr = mlx_get_data_addr(ftl->img, &ftl->bits_per_pixel,
			&ftl->line_length, &ftl->endian);
	rand_gradiant_init(ftl->color_end, ftl->color_start, ftl);
	fractol_render(*ftl);
	event_init(ftl);
	mlx_loop(ftl->mlx);
}
