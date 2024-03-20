/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agilles <agilles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 15:49:10 by agilles           #+#    #+#             */
/*   Updated: 2024/03/20 18:58:38 by agilles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

#include "mlx_linux/mlx.h"
#include "mlx_linux/mlx_int.h"

#include <math.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#define WIDTH 1200
#define HEIGHT 800

#define BLACK   0x000000
#define WHITE   0xFFFFFF
#define RED     0xFF0000
#define GREEN   0x00FF00
#define BLUE    0x0000FF
#define YELLOW  0xFFFF00
#define CYAN    0x00FFFF
#define MAGENTA 0xFF00FF
#define ORANGE  0xFFA500
#define PURPLE  0x800080
#define PINK    0xFFC0CB
#define GRAY    0x808080
#define BROWN   0xA52A2A

typedef struct	s_cord {

	double	x;
	double	y;
}				t_cord;

typedef struct	s_fractol{
	void	*mlx;
	void	*mlx_win;

	void	*img;
	char	*addr;

	int		bits_per_pixel;
	int		line_length;
	int		endian;

	t_cord	z;
	t_cord	c;

	int		i;
	int		j;
	int		k;
	int		max_it;

	double	zoom;
	double	shift_x;
	double	shift_y;
}				t_fractol;

int	trgb(int t, int r, int g, int b);
int	closed(int keycode, t_fractol *data);

double scale_min(double unscale_num, double new_min, double new_max);

t_cord	mand_suit(t_cord z1, t_cord z2);
t_cord	sqrt_comp(t_cord z);

void	event_init(t_fractol *ftl);
int		mouse_zoom(int keycode, int x, int y, t_fractol *data);
void	fractol_render(t_fractol ftl);
void	my_mlx_pixel_put(t_fractol *data, int x, int y, int color);


# endif
