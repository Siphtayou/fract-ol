/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agilles <agilles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:32:21 by agilles           #+#    #+#             */
/*   Updated: 2024/03/26 15:36:41 by agilles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	burning_zoom(int keycode, int x, int y, t_fractol *ftl)
{
	if (keycode == 4)
	{
		ftl->zoom *= 0.95;
		ftl->shift_x += (scale_min(x, -2, 2) * ftl->zoom) * 0.05;
		ftl->shift_y += (scale_min(y, -2, 2) * ftl->zoom) * 0.05;
	}
	else if (keycode == 5)
	{
		ftl->zoom *= 1.05;
		ftl->shift_x += (scale_min(x, -2, 2) * ftl->zoom) * 0.05;
		ftl->shift_y += (scale_min(y, -2, 2) * ftl->zoom) * 0.05;
	}
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

int	mouse_zoom(int keycode, int x, int y, t_fractol *ftl)
{
	if (!(strcmp(ftl->name, "Burning Ship")))
		return (burning_zoom(keycode, x, y, ftl));
	else if (keycode == 4)
	{
		ftl->zoom *= 0.95;
		ftl->shift_x += (scale_min(x, -2, 2) * ftl->zoom) * 0.05;
		ftl->shift_y += (scale_min(y, 2, -2) * ftl->zoom) * 0.05;
	}
	else if (keycode == 5)
	{
		ftl->zoom *= 1.05;
		ftl->shift_x += (scale_min(x, -2, 2) * ftl->zoom) * 0.05;
		ftl->shift_y += (scale_min(y, 2, -2) * ftl->zoom) * 0.05;
	}
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
