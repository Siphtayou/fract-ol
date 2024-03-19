/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agilles <agilles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 15:28:18 by agilles           #+#    #+#             */
/*   Updated: 2024/03/19 16:59:24 by agilles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double scale_min(double unscale_num, double new_min, double new_max)
{
	return ((new_max - new_min) * (unscale_num - 0) / (HEIGHT - 0) + new_min);
}

t_cord	mand_suit(t_cord z1, t_cord z2)
{
	t_cord	res;

	res.x = z1.x + z2.x;
	res.y = z1.y + z2.y;
	return (res);
}

t_cord	sqrt_comp(t_cord z)
{
	t_cord res;

	res.x = (z.x * z.x) - (z.y * z.y);
	res.y = 2 * z.x * z.y;
	return (res);
}
