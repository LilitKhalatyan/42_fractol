/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalaty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 17:12:54 by lkhalaty          #+#    #+#             */
/*   Updated: 2021/10/10 17:13:04 by lkhalaty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mandelbrot_itr(t_complex c, t_data *data)
{
	int			itr;
	t_complex	it;

	itr = 0;
	it.real = 0;
	it.magic = 0;
	while (ft_len(it) <= 4.0 && itr < data->max_it)
	{
		it = ft_square(it);
		it = ft_sum(it, c);
		itr++;
	}
	return (itr);
}

void	mandelbrot(t_data *data)
{
	int			x;
	int			y;
	int			itr;
	t_complex	c;

	x = 0;
	while (x < data->width)
	{
		y = 0;
		while (y < data->hight)
		{
			c.real = x / data->zoom + data->x1;
			c.magic = y / data->zoom + data->y1;
			itr = mandelbrot_itr(c, data);
			if (itr < data->max_it)
				my_mlx_pixel_put(data, x, y, itr * itr * COLOUR);
			else
				my_mlx_pixel_put(data, x, y, 0);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
}

void	mandelbrot_init(t_data *data)
{
	data->fractal = 1;
	data->hight = 600;
	data->width = 800;
	data->max_it = 50;
	data->zoom = 200;
	data->x1 = -2.05;
	data->y1 = -1.3;
}
