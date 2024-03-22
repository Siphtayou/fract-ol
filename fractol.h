/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agilles <agilles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 15:49:10 by agilles           #+#    #+#             */
/*   Updated: 2024/03/22 18:48:37 by agilles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

#include "mlx_linux/mlx.h"
#include "mlx_linux/mlx_int.h"

# include "printf_libft/ft_printf.h"

#include <math.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#define WIDTH 1200
#define HEIGHT 800
#define COLOR_STEPS 30

// *** 0 RANDOM GRADIANT | 1 BLACK & RANDOM GRADIANT ***
#define COLOR_MODE 1


#define BLACK		0x000000
#define WHITE		0xFFFFFF

#define RED			0xFF0000

#define GREEN		0x00FF00

#define BLUE		0x0000FF

#define YELLOW		0xFFFF00
#define DARK_YELLOW	0x5e6500

#define CYAN		0x00FFFF

#define MAGENTA		0xFF00FF

#define ORANGE		0xFFA500
#define BROWN		0xA52A2A

#define PURPLE		0x800080

#define PINK		0xFFC0CB

#define GRAY		0x808080



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

	int		color_start;
	int		color_end;
	int		color_tab[COLOR_STEPS];

	double	zoom;
	double	shift_x;
	double	shift_y;
}				t_fractol;

int	ft_strcmp(char *s1, char *s2);
int	trgb(int t, int r, int g, int b);
int ftl_close(t_fractol *ftl);

double scale_min(double unscale_num, double new_min, double new_max);

t_cord	mand_suit(t_cord z1, t_cord z2);
t_cord	sqrt_comp(t_cord z);
// t_cord	sqrt_comp(t_cord z, t_cord c);

void	event_init(t_fractol *ftl);
int		mouse_zoom(int keycode, int x, int y, t_fractol *data);
int		cross_closed(t_fractol *ftl);
void	rand_gradiant_init(int c_start, int c_end, t_fractol *ftl);
int		key_press(int keycode, t_fractol *ftl);
void	fractol_render(t_fractol ftl);
void	my_mlx_pixel_put(t_fractol *data, int x, int y, int color);
void	key_precision(int keycode, t_fractol *ftl);


# endif
