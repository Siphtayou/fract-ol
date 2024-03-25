/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agilles <agilles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 13:54:22 by agilles           #+#    #+#             */
/*   Updated: 2024/03/25 17:20:43 by agilles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	extract_rgb(int hex_start, int hex_end, t_color *color)
{
	color->r_start = (hex_start >> 16) & 0xFF;
	color->r_end = (hex_end >> 16) & 0xFF;
	color->g_start = (hex_start >> 8) & 0xFF;
	color->g_end = (hex_end >> 8) & 0xFF;
	color->b_start = (hex_start) & 0xFF;
	color->b_end = (hex_end) & 0xFF;
}

void	rand_gradiant_init(int c_start, int c_end, t_fractol *ftl)
{
	double	r;
	int		i;
	t_color	color;

	i = -1;
	extract_rgb(c_start, c_end, &color);
	while (++i <= (COLOR_STEPS - 1))
	{
		r = (double)i / COLOR_STEPS;
		color.r = (int)(color.r_start) + ((color.r_end) - (color.r_start) * r);
		color.g = (int)(color.g_start) + ((color.g_end) - (color.g_start) * r);
		color.b = (int)(color.b_start) + ((color.b_end) - (color.b_start) * r);
		ftl->color_tab[i] = trgb(0, color.r, color.g, color.b);
	}
}
