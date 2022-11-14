/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_fps_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderouba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 11:58:10 by aderouba          #+#    #+#             */
/*   Updated: 2022/11/14 15:01:08 by aderouba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	key_fps(int keycode, t_vars *vars)
{
	if (keycode == XK_w)
		zoom_fps(vars, 1.05);
	else if (keycode == XK_s)
		zoom_fps(vars, 1.0 / 1.05);
	else if (keycode == XK_a)
		translate_fps(vars, 10.0, 0.0);
	else if (keycode == XK_d)
		translate_fps(vars, -10.0, 0.0);
	else if (keycode == XK_q)
		translate_fps(vars, 0.0, 10.0);
	else if (keycode == XK_e)
		translate_fps(vars, 0.0, -10.0);
	else if (keycode == XK_Up)
		rotate_fps(vars, 1.0, 'x');
	else if (keycode == XK_Down)
		rotate_fps(vars, -1.0, 'x');
	else if (keycode == XK_Left)
		rotate_fps(vars, 1.0, 'z');
	else if (keycode == XK_Right)
		rotate_fps(vars, -1.0, 'z');
	else if (keycode == XK_r)
		reset_fps(vars);
}

void	reset_fps(t_vars *vars)
{
	free_map(vars);
	init_map_fps(vars);
	vars->map.redraw = 1;
}

void	init_map_fps(t_vars *vars)
{
	vars->map.angle_x = 0;
	vars->map.angle_y = 0;
	vars->map.angle_z = 0;
	vars->map.zoom = 1.0;
	vars->map.redraw = 1;
	paste_cpy_to_map(vars);
	first_zoom(vars);
	translate_fps(vars, 1920.0 / 4, 0.0);
	vars->map.x = 1920.0 / 2.0;
	vars->map.y = 1080.0 / 2.0;
	calculate_projection_fps(vars);
}

void	draw_render_fast_fps(t_vars *vars)
{
	int	y00;
	int	y0w;
	int	yh0;
	int	yhw;

	y00 = vars->map.map[0][0].y;
	y0w = vars->map.map[0][vars->map.w - 1].y;
	yh0 = vars->map.map[vars->map.h - 1][0].y;
	yhw = vars->map.map[vars->map.h - 1][vars->map.w - 1].y;
	if (y00 <= y0w && y00 <= yh0)
		draw_render_fast_00hw(vars);
	else if (yh0 <= y00 && yh0 <= yhw)
		draw_render_fast_h00w(vars);
	else if (yhw <= yh0 && yhw <= y0w)
		draw_render_fast_hw00(vars);
	else if (y0w <= yhw && y0w <= y00)
		draw_render_fast_0wh0(vars);
}

void	draw_render_exact_fps(t_vars *vars)
{
	int	y00;
	int	y0w;
	int	yh0;
	int	yhw;

	y00 = vars->map.map[0][0].y;
	y0w = vars->map.map[0][vars->map.w - 1].y;
	yh0 = vars->map.map[vars->map.h - 1][0].y;
	yhw = vars->map.map[vars->map.h - 1][vars->map.w - 1].y;
	if (y00 <= y0w && y00 <= yh0)
		draw_render_exact_00hw(vars);
	else if (yh0 <= y00 && yh0 <= yhw)
		draw_render_exact_h00w(vars);
	else if (yhw <= yh0 && yhw <= y0w)
		draw_render_exact_hw00(vars);
	else if (y0w <= yhw && y0w <= y00)
		draw_render_exact_0wh0(vars);
}
