/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agilles <agilles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 13:54:22 by agilles           #+#    #+#             */
/*   Updated: 2024/03/22 16:37:23 by agilles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

typedef struct s_color
{
	int	r;
	int	r_start;
	int	r_end;
	int	b;
	int	b_start;
	int	b_end;
	int	g;
	int	g_start;
	int	g_end;
}	t_color;

void extractRGB(int hex_start, int hex_end, t_color *color) {
    color->r_start = (hex_start >> 16) & 0xFF;
	color->r_end = (hex_end >> 16) & 0xFF;
    color->g_start = (hex_start >> 8) & 0xFF;
	color->g_end = (hex_end >> 8) & 0xFF;
    color->b_start = (hex_start) & 0xFF;
	color->b_end = (hex_end) & 0xFF;
}

void	rand_gradiant_init(int c_start, int c_end, t_fractol *ftl)
{
	double	ratio;
	int		i;
	t_color	color;

	i = -1;
	extractRGB(c_start, c_end, &color);
	while (++i <= (COLOR_STEPS - 1))
	{
		ratio = (double)i / COLOR_STEPS;
		color.r = (int)(color.r_start) + ((color.r_end) - (color.r_start) * ratio);
		color.g = (int)(color.g_start) + ((color.g_end) - (color.g_start) * ratio);
		color.b = (int)(color.b_start) + ((color.b_end) - (color.b_start) * ratio);
		// printf("%x\n", trgb(0, color.r, color.g, color.b));
		ftl->color_tab[i] = trgb(0, color.r, color.g, color.b);
	}
}
