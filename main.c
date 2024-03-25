/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agilles <agilles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 17:30:06 by agilles           #+#    #+#             */
/*   Updated: 2024/03/25 18:07:11 by agilles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int ac, char **av)
{
	t_fractol	*ftl;

	if (ft_strcmp(av[1], "Mandelbrot") && ft_strcmp(av[1], "Julia")
		&& ft_strcmp(av[1], "Burning Ship"))
		return (ftl_error());
	else if (ac == 1 || ac == 3 || ac > 4)
		return (ftl_error());
	else if (!(ft_strcmp(av[1], "Mandelbrot")) && ac > 2)
		return (ftl_error());
	else if (!(ft_strcmp(av[1], "Burning Ship")) && ac > 2)
		return (ftl_error());
	else if (!(ft_strcmp(av[1], "Julia")) && ac != 4)
		return (ftl_error());
	srand(time(NULL));
	ftl = ftl_mlx_init(ftl, av[1]);
	if (!ftl)
		return (1);
	if (!(ft_strcmp(ftl->name, "Julia")))
	{
		ftl->jx = ftl_atodbl(av[2], 0);
		ftl->jy = ftl_atodbl(av[3], 0);
	}
	fractol_render(*ftl);
	event_init(ftl);
	mlx_loop(ftl->mlx);
}
