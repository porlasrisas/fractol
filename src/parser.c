/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guigonza <guigonza@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 14:12:51 by guigonza          #+#    #+#             */
/*   Updated: 2025/04/08 16:22:41 by guigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	ft_error(char *msg)
{
	ft_putstr_fd(msg, 2);
	exit(1);
}

int	parse_args(int ac, char **av, t_data *data)
{
	if (ac < 2)
		ft_error("Error: Correct usage:\n"
			"./fractol mandelbrot\n"
			"./fractol julia [re] [im]");
	if (!ft_strncmp(av[1], "mandelbrot", ft_strlen("mandelbrot")))
		data->t_iter_func = &mandelbrot_iterations;
	else if (!ft_strncmp(av[1], "julia", ft_strlen("julia")))
	{
		data->t_iter_func = &julia_iterations;
		data->julia_re = -0.8;
		data->julia_im = 0.156;
		if (ac == 4)
		{
			if (!ft_is_valid_float(av[2]) || !ft_is_valid_float(av[3]))
				ft_error("Error: invalid floats for julia re/im\n");
			data->julia_re = ft_atof(av[2]);
			data->julia_im = ft_atof(av[3]);
		}
		else if (ac != 2)
			ft_error("Error: wrong input");
	}
	else
		ft_error("Error: unrecognized fractal\n");
	return (0);
}
