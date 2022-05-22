/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalaty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 17:13:47 by lkhalaty          #+#    #+#             */
/*   Updated: 2021/10/10 17:13:49 by lkhalaty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	close(void)
{
	exit(1);
	return (0);
}

int	ft_valid_parameter_list(void)
{
	printf("You should pass as a parameter one of fractal set names below\n");
	printf("Mandelbrot\n");
	printf("Julia\n");
	exit (-1);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}

int	main(int argc, char **argv)
{
	t_data	data;

	data.mlx = mlx_init();
	data.mlx_win = mlx_new_window(data.mlx, WIDTH, HIGHT, "Fractal");
	data.img = mlx_new_image(data.mlx, WIDTH, HIGHT);
	data.addr = mlx_get_data_addr(data.img,
			&data.bpp, &data.line_length, &data.endian);
	if (argc >= 2)
	{
		if (ft_str_compare(argv[1], "Mandelbrot"))
			mandelbrot_init(&data);
		else if (ft_str_compare(argv[1], "Julia"))
			julia_init(&data);
		else
			ft_valid_parameter_list();
	}
	else
		ft_valid_parameter_list();
	draw_win(&data);
	mlx_hook(data.mlx_win, 6, 1L < 6, mouse_julia, &data);
	mlx_hook(data.mlx_win, 2, 1L << 0, close, &data);
	mlx_hook(data.mlx_win, 17, 0, close, &data);
	mlx_mouse_hook(data.mlx_win, zoom, &data);
	mlx_loop(data.mlx);
	return (0);
}
