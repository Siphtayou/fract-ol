/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agilles <agilles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 15:28:18 by agilles           #+#    #+#             */
/*   Updated: 2024/03/22 18:48:24 by agilles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	scale_min(double unscale_num, double new_min, double new_max)
{
	return ((new_max - new_min) * (unscale_num - 0) / (HEIGHT - 0) + new_min);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	if (!s1 || !s2)
		return (1);
	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] == s2[i])
			i++;
		else
			return (s1[i] - s2[i]);
	}
	return (0);
}

void	fractol_render(t_fractol ftl)
{
	int			color;

	ftl.i = -1;
	while (++ftl.i <= WIDTH)
	{
		ftl.j = 0;
		while (++ftl.j <= HEIGHT)
		{
			ftl.z.x = 0.0;
			ftl.z.y = 0.0;
			ftl.c.x = (scale_min(ftl.i, -2, 2) * ftl.zoom) + ftl.shift_x;
			ftl.c.y = (scale_min(ftl.j, 2, -2) * ftl.zoom) + ftl.shift_y;
			ftl.k = 0;
			while (ftl.k < ftl.max_it)
			{
				ftl.z = mand_suit(sqrt_comp(ftl.z), ftl.c);
				if ((ftl.z.x * ftl.z.x) + (ftl.z.y * ftl.z.y) > 4)
				{
					color = BLACK;
					break ;
				}
				ftl.k++;
			}
			if (ftl.k == ftl.max_it)
				color = BLACK;
			else
				color = ftl.color_tab[ftl.k % COLOR_STEPS];
			my_mlx_pixel_put(&ftl, ftl.i, ftl.j, color);
		}
	}
	mlx_put_image_to_window(ftl.mlx, ftl.mlx_win, ftl.img, 0, 0);
}

t_cord	mand_suit(t_cord z1, t_cord z2)
{
	t_cord	res;

	res.x = z1.x + z2.x;
	res.y = z1.y + z2.y;
	return (res);
}

	// ***BURNING SHIP INVERSE***
	// ***ajouter (, t_cord) c en param***
	// res.x = (z.x * z.x) - (z.y * z.y) + c.x;
	// res.y = 2 * fabs(z.x * z.y) + c.y;
t_cord	sqrt_comp(t_cord z)
{
	t_cord	res;

	res.x = (z.x * z.x) - (z.y * z.y);
	res.y = 2 * z.x * z.y;
	return (res);
}
