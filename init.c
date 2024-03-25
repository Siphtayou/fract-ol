/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agilles <agilles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 17:35:33 by agilles           #+#    #+#             */
/*   Updated: 2024/03/25 18:06:31 by agilles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_fractol	*fractol_init(t_fractol *ftl)
{
	if (COLOR_MODE)
		ftl->color_start = BLACK;
	else
		ftl->color_start = trgb(0, rand() % 255, rand() % 255, rand() % 255);
	ftl->i = -1;
	ftl->j = -1;
	ftl->k = 0;
	ftl->max_it = 100;
	ftl->zoom = 1.0;
	ftl->shift_x = 0.0;
	ftl->shift_y = 0.0;
	if (!(ft_strcmp(ftl->name, "Burning Ship")))
		ftl->color_end = RED;
	else
		ftl->color_end = trgb(0, rand() % 255, rand() % 255, rand() % 255);
	return (ftl);
}

t_fractol	*ftl_mlx_init(t_fractol *ftl, char *title)
{
	ftl = malloc(sizeof(t_fractol));
	if (!ftl)
		return (NULL);
	ftl->name = title;
	ftl = fractol_init(ftl);
	ftl->mlx = mlx_init();
	ftl->mlx_win = mlx_new_window(ftl->mlx, WIDTH, HEIGHT, title);
	ftl->img = mlx_new_image(ftl->mlx, WIDTH, HEIGHT);
	ftl->addr = mlx_get_data_addr(ftl->img, &ftl->bits_per_pixel,
			&ftl->line_length, &ftl->endian);
	rand_gradiant_init(ftl->color_end, ftl->color_start, ftl);
	return (ftl);
}

void	event_init(t_fractol *ftl)
{
	mlx_hook(ftl->mlx_win,
		KeyPress,
		KeyPressMask,
		&key_press,
		ftl);
	mlx_hook(ftl->mlx_win,
		DestroyNotify,
		StructureNotifyMask,
		&ftl_close,
		ftl);
	mlx_hook(ftl->mlx_win,
		ButtonPress,
		ButtonPressMask,
		&mouse_zoom,
		ftl);
}
