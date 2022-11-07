/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bonus.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderouba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 17:25:26 by aderouba          #+#    #+#             */
/*   Updated: 2022/11/07 16:15:54 by aderouba         ###   ########.fr       */
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

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	t_data	img;
	t_point	**map;
	t_pixel	**proj;
	int		map_w;
	int		map_h;
	double	x;
	double	y;
	double	angle_x;
	double	angle_y;
	double	zoom;
	int		redraw;
}	t_vars;

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
}	t_color;

// fdf_bonus.c
int		mlx_close(t_vars *vars);
int		key_hook(int keycode, t_vars *vars);
int		mouse_hook(int mousecode, int x, int y, t_vars *vars);
int		render(t_vars *vars);
int		main(int argc, char **argv);

// color_bonus.c
int		create_rgb(int r, int g, int b);
int		combine_color(int color1, int color2, float percent1, float percent2);
int		smouth_color(t_pixel start, t_pixel end, t_pixel current);

// draw_utils_bonus.c
void	draw_pixel(t_data data, int x, int y, int color);
void	draw_line(t_vars *vars, t_pixel start, t_pixel end);
void	clear_screen(t_vars *vars);

// projection_bonus.c
void	init_proj(t_vars *vars);
void	calculate_projection(t_vars *vars);

// parsing_bonus.c
t_point	split_element_to_map_point(int x, int y, char *element);
void	parse_line(t_vars *vars, char **split_result);
int		get_line(t_vars *vars, int fd);
t_vars	get_map_from_agr(t_vars *vars, char **argv);

// parsing2_bonus.c
t_point	*add_value(t_point *tab, int size, t_point value);
void	add_line(t_vars *vars, t_point *line);
int		value_of_char(char c, char *base);
int		atoi_hex(char *nptr, char *base);

// utils_bonus.c
void	free_vars(t_vars *vars);

// space_operation_bonus.c
void	translate(t_vars *vars, double x, double y);
void	zoom(t_vars *vars, double zoom, int x, int y);

#endif
