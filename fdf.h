/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderouba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 17:25:26 by aderouba          #+#    #+#             */
/*   Updated: 2022/11/15 08:47:43 by aderouba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/libft.h"
# include "mlx_linux/mlx.h"
# include "mlx_linux/mlx_int.h"
# include <math.h>
# include <fcntl.h>

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_point
{
	double	x;
	double	y;
	double	z;
	int		color;
}	t_point;

typedef struct s_pixel
{
	double	x;
	double	y;
	int		color;
}	t_pixel;

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
}	t_color;

typedef struct s_map
{
	t_point	**map;
	t_pixel	**proj;
	int		w;
	int		h;
	double	x;
	double	y;
	double	zoom;
	int		redraw;
}	t_map;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	t_data	img;
	t_map	map;
}	t_vars;

// fdf.c
int		mlx_close(t_vars *vars);
int		key_hook(int keycode, t_vars *vars);
int		render(t_vars *vars);
int		main(int argc, char **argv);

// color.c
int		create_rgb(int r, int g, int b);
int		combine_color(int color1, int color2, float percent1, float percent2);
int		smouth_color(t_pixel start, t_pixel end, t_pixel current);

// draw_utils.c
void	draw_pixel(t_data data, int x, int y, int color);
void	draw_line(t_vars *vars, t_pixel start, t_pixel end);
void	clear_screen(t_vars *vars);

// projection.c
void	init_proj(t_vars *vars);
void	calculate_projection(t_vars *vars);

// parsing.c
t_point	split_element_to_map_point(int x, int y, char *element);
void	parse_line(t_vars *vars, char **split_result);
int		get_line(t_vars *vars, int fd);
t_vars	get_map_from_agr(t_vars *vars, char **argv);

// parsing2.c
t_point	*add_value(t_point *tab, int size, t_point value);
void	add_line(t_vars *vars, t_point *line);
void	error_parse_map(t_vars *vars, char **split_result, t_point *tab);

// utils.c
void	free_vars(t_vars *vars);

#endif
