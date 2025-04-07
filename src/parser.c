/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guigonza <guigonza@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 14:12:51 by guigonza          #+#    #+#             */
/*   Updated: 2025/04/07 19:01:12 by guigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	parse_args(int ac, char **av, t_data *data)
{
	if (ac < 2)
	{
		ft_putstr_fd("Error! Correct usage: ./fractol mandelbrot\n", 2);
		ft_putstr_fd("                      ./fractol julia [re] [im]", 2);
		exit (1);
	}
	if (!ft_strncmp(av[1], "mandelbrot", ft_strlen("mandelbrot")))
		data->t_iter_func = &mandelbrot_iterations;

	else if (!ft_strncmp(av[1], "julia", ft_strlen("julia")))
	{
		data->t_iter_func = &julia_iterations;
		data->julia_re = -0.8;
		data->julia_im = 0.156;
		if (ac >= 4)
		{
			data->julia_re = ft_atof(av[2]);
			data->julia_im = ft_atof(av[3]);
		}
	}
	else if (!ft_strncmp(av[1], "lorenz", ft_strlen("lorenz")))
	{
		data->t_iter_func = &lorenz_iterations;
		data->lorenz_sigma = 10.0;
		data->lorenz_rho = 28.00;
		data->lorenz_beta = 8.0 / 3.0;
	}
	return (0);
}
