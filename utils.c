/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agilles <agilles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 15:28:18 by agilles           #+#    #+#             */
/*   Updated: 2024/03/25 17:37:02 by agilles          ###   ########.fr       */
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

double	ftl_atodbl(char *nb, int i)
{
	double	frac_part;
	double	pow;
	long	int_part;
	int		s;

	int_part = 0;
	frac_part = 0;
	pow = 1;
	s = 1;
	while (nb[i] == 32 || (nb[i] >= 9 && nb[i] == 13))
		i++;
	while (nb[i] == '-' || nb[i] == '+')
		if (nb[i++] == '-')
			s *= -1;
	while (nb[i] >= 48 && nb[i] <= 57 && nb[i] != '.')
		int_part = int_part * 10 + nb[i++] - '0';
	if (nb[i] == '.')
		i++;
	while (nb[i] >= 48 && nb[i] <= 57 && nb[i])
	{
		pow /= 10;
		frac_part = frac_part + (nb[i++] - '0') * pow;
	}
	return (int_part + frac_part * s);
}
