/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agilles <agilles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 15:49:10 by agilles           #+#    #+#             */
/*   Updated: 2024/03/19 18:06:26 by agilles          ###   ########.fr       */
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

#define WIDTH 800
#define HEIGHT 800

typedef struct	s_data {
	void	*mlx;
	void	*mlx_win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct	s_cord {

	double	x;
	double	y;
}				t_cord;

double scale_min(double unscale_num, double new_min, double new_max);

t_cord	mand_suit(t_cord z1, t_cord z2);
t_cord	sqrt_comp(t_cord z);


# endif
