#ifndef FRACTOL_H
    #define FRACTOL_H

    # include <stdlib.h>
    # include <unistd.h>
    # include <math.h>
    # include "mlx.h"
    # include "libft.h"
    # include "ft_printf.h"

    struct s_data;
    typedef struct s_data t_data;
    
    typedef int (*t_iter_func)(double, double, struct s_data *);

    typedef struct s_data
    {
        void	*mlx_ptr;
        void	*win_ptr;
        void    *img_ptr;
        int		width;
        int		height;
        char	*addr;            // Dirección de memoria para escribir los píxeles
        int		bits_per_pixel;   // Normalmente 32
        int		line_length;      // Número de bytes de cada línea de píxeles
        int		endian;
        double  zoom;
        double  offset_x;
        double  offset_y;
        int     max_iter;
        double julia_re;
        double julia_im;
        t_iter_func iter_func;

    }       t_data;
    int		close_window(void *param);
    int		key_hook(int keycode, void *param);
    int init_image(t_data *data);
    void put_pixel(t_data *data, int x, int y, int color);
    int calculate_color(int i, int max_iter);
    int mandelbrot_iterations(double cr, double ci, t_data *data);
    int julia_iterations(double x, double y, t_data *data);
    void   draw_line(t_data *d, int y,
        int (*iteration_func)(double, double, t_data *));
    void draw_fractal(t_data *d, t_iter_func iteration_func);
    double  ft_atof(const char *str);
    int parse_args(int ac, char **av, t_data *data);
    int mouse_hook(int button, int x, int y, void *param);









    #endif