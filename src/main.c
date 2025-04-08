/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guigonza <guigonza@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 14:12:44 by guigonza          #+#    #+#             */
/*   Updated: 2025/04/08 13:56:22 by guigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	init_values(t_data *data)
{
	data->width = 800;
	data->height = 600;
	data->zoom = 1.0;
	data->offset_x = 0.0;
	data->offset_y = 0.0;
	data->max_iter = 50;
}

int	main(int ac, char **av)
{
	t_data	data;

	init_values(&data);
	if (parse_args(ac, av, &data) == 1)
		return (1);
	data.mlx_ptr = mlx_init();
	if (!data.mlx_ptr)
		return (ft_putstr_fd("Error: no se pudo iniciar la minilibx\n", 2), 1);
	data.win_ptr = mlx_new_window(data.mlx_ptr, data.width, data.height,
			"Fractol");
	if (!data.win_ptr)
		return (ft_putstr_fd("Error: no se pudo crear la ventana\n", 2), 1);
	init_image(&data);
	if (!data.img_ptr)
		return (1);
	draw_fractal(&data, data.t_iter_func);
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.img_ptr, 0, 0);
	mlx_hook(data.win_ptr, 17, 0, close_window, &data);
	mlx_hook(data.win_ptr, 2, 1L << 0, key_hook, &data);
	mlx_mouse_hook(data.win_ptr, mouse_hook, &data);
	mlx_loop(data.mlx_ptr);
	return (0);
}
