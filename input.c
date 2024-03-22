/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agilles <agilles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 13:54:53 by agilles           #+#    #+#             */
/*   Updated: 2024/03/22 16:33:07 by agilles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mouse_zoom(int keycode, int x, int y, t_fractol *ftl)
{
	(void)x;
	(void)y;
	if (keycode == 4)
		ftl->zoom *= 0.95;
	else if (keycode == 5)
		ftl->zoom *= 1.05;
	else if (keycode == 2)
	{
		ftl->zoom = 1;
		ftl->max_it = 150;
		ftl->shift_x = 0;
		ftl->shift_y = 0;
	}
	fractol_render(*ftl);
	return (0);
}

int	ftl_close(t_fractol *ftl)
{
	mlx_destroy_image(ftl->mlx, ftl->img);
	mlx_destroy_window(ftl->mlx, ftl->mlx_win);
	mlx_destroy_display(ftl->mlx);
	free(ftl->mlx);
	free(ftl);
	exit (0);
}

//  *** 65451 + | - 65453 ***
//  ***6536- 1LEFT 2UP 3RIGHT 4DOWN***
int	key_press(int keycode, t_fractol *ftl)
{
	if (keycode == 65307)
	{
		ftl_close(ftl);
		exit (0);
	}
	else if (keycode == 97)
		ftl->shift_x -= 0.5 * ftl->zoom;
	else if (keycode == 100)
		ftl->shift_x += 0.5 * ftl->zoom;
	else if (keycode == 119)
		ftl->shift_y += 0.5 * ftl->zoom;
	else if (keycode == 115)
		ftl->shift_y -= 0.5 * ftl->zoom;
	else if (keycode == 65451)
		ftl->max_it += 10;
	else if (keycode == 65453)
	{
		if (ftl->max_it > 20)
			ftl->max_it -= 10;
	}
	key_precision(keycode, ftl);
	fractol_render(*ftl);
	return (1);
}

void	key_precision(int keycode, t_fractol *ftl)
{
	if (keycode == 65361)
		ftl->shift_x -= 0.1 * ftl->zoom;
	else if (keycode == 65363)
		ftl->shift_x += 0.1 * ftl->zoom;
	else if (keycode == 65362)
		ftl->shift_y += 0.1 * ftl->zoom;
	else if (keycode == 65364)
		ftl->shift_y -= 0.1 * ftl->zoom;
	fractol_render(*ftl);
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
