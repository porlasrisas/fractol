/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guigonza <guigonza@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 14:12:33 by guigonza          #+#    #+#             */
/*   Updated: 2025/04/07 16:51:53 by guigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	close_window(void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (data->img_ptr)
		mlx_destroy_image(data->mlx_ptr, data->img_ptr);
	if (data->win_ptr)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	exit(0);
	return (0);
}

int	key_hook(int keycode, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (keycode == 53 || keycode == 65307)
		close_window(data);
	if (keycode == 123 || keycode == 65361)
		data->offset_x -= 0.1 / data->zoom;
	if (keycode == 124 || keycode == 65363)
		data->offset_x += 0.1 / data->zoom;
	if (keycode == 126 || keycode == 65362)
		data->offset_y -= 0.1 / data->zoom;
	if (keycode == 125 || keycode == 65364)
		data->offset_y += 0.1 / data->zoom;
	if (keycode == 30 || keycode == 65451)
		data->zoom *= 1.1;
	if (keycode == 44 || keycode == 65453)
		data->zoom /= 1.1;
	draw_fractal(data, data->t_iter_func);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, 0, 0);
	return (0);
}

int	mouse_hook(int button, int x, int y, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	(void)x;
	(void)y;
	if (button == 4)
		data->zoom *= 1.1;
	else if (button == 5)
		data->zoom /= 1.1;
	draw_fractal(data, data->t_iter_func);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, 0, 0);
	return (0);
}
