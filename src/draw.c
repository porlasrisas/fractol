#include "fractol.h"

int init_image(t_data *data)
{
    data->img_ptr = mlx_new_image(data->mlx_ptr, data->width, data->height);
    if (!data->img_ptr)
    {
        ft_printf("Error: no se pudo crear la imagen\n");
        return (1);
    }
    data->addr = mlx_get_data_addr(data->img_ptr, &data->bits_per_pixel, &data->line_length, &data->endian);
    return (0);
}
void put_pixel(t_data *data, int x, int y, int color)
{
    char *dst;
    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int *)dst = color;
}

