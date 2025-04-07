/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guigonza <guigonza@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 14:13:01 by guigonza          #+#    #+#             */
/*   Updated: 2025/04/07 19:07:33 by guigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "ft_printf.h"
# include "libft.h"
# include "mlx.h"
# include <math.h>
# include <stdlib.h>
# include <unistd.h>

// struct	s_data;
// typedef struct s_data
// {

// }	t_data;
// typedef

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	int		width;
	int		height;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	double	zoom;
	double	offset_x;
	double	offset_y;
	int		max_iter;
	double	julia_re;
	double	julia_im;
	int		(*t_iter_func)(double, double, struct s_data *);
	double	re;
	double	im;
    double  lorenz_x;
    double  lorenz_y;
    double  lorenz_z;
    double  lorenz_sigma;
    double  lorenz_rho;
    double  lorenz_beta;
	double lorenz_dx;        // Derivada de x
    double lorenz_dy;        // Derivada de y
    double lorenz_dz;        // Derivada de z
}			t_data;
int			close_window(void *param);
int			key_hook(int keycode, void *param);
int			init_image(t_data *data);
void		put_pixel(t_data *data, int x, int y, int color);
int			calculate_color(int i, int max_iter);
int			mandelbrot_iterations(double cr, double ci, t_data *data);
int			julia_iterations(double x, double y, t_data *data);
void		draw_line(t_data *d, int y, int (*iteration_func)(double, double,
					t_data *));
void		draw_fractal(t_data *d, int (*t_iter_func)(double, double,
					struct s_data *));
double		ft_atof(const char *str);
int			parse_args(int ac, char **av, t_data *data);
int			mouse_hook(int button, int x, int y, void *param);
int	lorenz_iterations(double x, double y, t_data *data);


#endif