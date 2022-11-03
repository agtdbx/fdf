/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderouba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 17:25:26 by aderouba          #+#    #+#             */
/*   Updated: 2022/11/03 17:34:33 by aderouba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/libft.h"
# include "mlx_linux/mlx.h"
# include "mlx_linux/mlx_int.h"
# include <math.h>

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	t_data	img;
}	t_vars;

typedef struct s_pixel
{
	int	x;
	int	y;
	int	color;
}	t_pixel;

// fdf.c
int		create_rgb(int r, int g, int b);
int		mlx_close(t_vars *vars);
int		event_hook(int keycode, t_vars *vars);
int		render(t_vars *vars);
int		main(void);

// draw_utils.c
void	draw_pixel(t_data data, int x, int y, int color);
void	draw_line(t_vars *vars, t_pixel start, t_pixel end);
void	draw_circle(t_vars *vars, t_pixel center, int radius, int width);

#endif
