/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agilles <agilles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 15:49:08 by agilles           #+#    #+#             */
/*   Updated: 2024/03/25 18:02:23 by agilles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_fractol *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	ftl_error(void)
{
	ft_printf("Error : Bad parameters supplied to ./fractol\n");
	ft_printf("\n***THIS IS HOW TO CALL IT***\n");
	ft_printf("\nMandelbrot : ./fractol Mandelbrot\n");
	ft_printf("Julia : ./fractol Julia z c (for exemple z = -0.4 c = 0.6)\n");
	ft_printf("Burning Ship : ./fractol \"Burning Ship\"\n\n");
	ft_printf("Enjoy :D\n");
	return (1);
}

void	ftl_cord(t_fractol *ftl)
{
	ftl->z.x = (scale_min(ftl->i, -2, 2) * ftl->zoom) + ftl->shift_x;
	ftl->z.y = (scale_min(ftl->j, 2, -2) * ftl->zoom) + ftl->shift_y;
	if (!(ft_strcmp(ftl->name, "Julia")))
	{
		ftl->c.x = ftl->jx;
		ftl->c.y = ftl->jy;
	}
	else if (!(ft_strcmp(ftl->name, "Burning Ship")))
	{
		ftl->z.x = (scale_min(ftl->i, -2, 2) * ftl->zoom) + ftl->shift_x;
		ftl->z.y = (scale_min(ftl->j, -2, 2) * ftl->zoom) + ftl->shift_y;
		ftl->c.x = ftl->z.x;
		ftl->c.y = ftl->z.y;
	}
	else if (!(ft_strcmp(ftl->name, "Mandelbrot")))
	{
		ftl->c.x = ftl->z.x;
		ftl->c.y = ftl->z.y;
	}
	ftl->k = 0;
}

void	fractol_render(t_fractol ftl)
{
	ftl.i = -1;
	while (++ftl.i <= WIDTH)
	{
		ftl.j = 0;
		while (++ftl.j <= HEIGHT)
		{
			ftl_cord(&ftl);
			while (ftl.k < ftl.max_it)
			{
				ftl.z = ftl_suit(&ftl);
				if ((ftl.z.x * ftl.z.x) + (ftl.z.y * ftl.z.y) > 4)
					break ;
				ftl.k++;
			}
			if (ftl.k == ftl.max_it)
				ftl.color = BLACK;
			else if (COLOR_MODE == 0 || COLOR_MODE == 1)
				ftl.color = ftl.color_tab[ftl.k % COLOR_STEPS];
			else
				ftl.color = ftl.color_tab[ftl.k];
			my_mlx_pixel_put(&ftl, ftl.i, ftl.j, ftl.color);
		}
	}
	mlx_put_image_to_window(ftl.mlx, ftl.mlx_win, ftl.img, 0, 0);
}

t_cord	ftl_suit(t_fractol *ftl)
{
	t_cord	res;
	t_cord	res2;

	if (!(ft_strcmp(ftl->name, "Burning Ship")))
	{
		res.x = (ftl->z.x * ftl->z.x) - (ftl->z.y * ftl->z.y) + ftl->c.x;
		res.y = 2 * fabs(ftl->z.x * ftl->z.y) + ftl->c.y;
		return (res);
	}
	else
	{
		res.x = (ftl->z.x * ftl->z.x) - (ftl->z.y * ftl->z.y);
		res.y = 2 * ftl->z.x * ftl->z.y;
		res2.x = res.x + ftl->c.x;
		res2.y = res.y + ftl->c.y;
	}
	return (res2);
}
