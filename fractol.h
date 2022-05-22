/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalaty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 17:15:56 by lkhalaty          #+#    #+#             */
/*   Updated: 2021/10/10 17:15:59 by lkhalaty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define COLOUR		265
# define WIDTH		800
# define HIGHT		600

# include <math.h>
# include <mlx.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_data
{
	int			width;
	int			hight;
	void		*img;
	char		*addr;
	int			bpp;
	int			line_length;
	int			endian;
	void		*mlx;
	void		*mlx_win;
	double		x1;
	double		y1;
	int			max_it;
	double		zoom;
	double		c_r;
	double		c_m;
	int			fractal;
}				t_data;

typedef struct s_complex
{
	double		real;
	double		magic;
}				t_complex;

t_complex			ft_sum(t_complex a, t_complex b);
t_complex			ft_square(t_complex a);
double				ft_len(t_complex x);

void				mandelbrot_init(t_data *data);
void				julia_init(t_data *data);

void				mandelbrot(t_data *data);
void				julia(t_data *data);

void				my_mlx_pixel_put(t_data *data, int x, int y, int color);
int					ft_str_compare(char *s1, char *s2);

int					mouse_julia(int x, int y, t_data *data);
int					close(void);
int					zoom(int button, int x, int y, t_data *data);
void				draw_win(t_data *data);

#endif
