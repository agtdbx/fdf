/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_iso_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderouba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:07:45 by aderouba          #+#    #+#             */
/*   Updated: 2022/11/14 15:04:20 by aderouba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	key_iso(int keycode, t_vars *vars)
{
	if (keycode == XK_w || keycode == XK_Up)
		translate_iso(vars, 0, 10.0);
	else if (keycode == XK_s || keycode == XK_Down)
		translate_iso(vars, 0, -10.0);
	else if (keycode == XK_a || keycode == XK_Left)
		translate_iso(vars, 10.0, 0);
	else if (keycode == XK_d || keycode == XK_Right)
		translate_iso(vars, -10.0, 0);
	else if (keycode == XK_u)
		rotate_iso(vars, 1.0, 'x');
	else if (keycode == XK_i)
		rotate_iso(vars, -1.0, 'x');
	else if (keycode == XK_j)
		rotate_iso(vars, -1.0, 'y');
	else if (keycode == XK_k)
		rotate_iso(vars, 1.0, 'y');
	else if (keycode == XK_n)
		rotate_iso(vars, 1.0, 'z');
	else if (keycode == XK_m)
		rotate_iso(vars, -1.0, 'z');
	else if (keycode == XK_p)
		vars->map.autorotation = !vars->map.autorotation;
	else if (keycode == XK_r)
		reset_iso(vars);
}

void	reset_iso(t_vars *vars)
{
	free_map(vars);
	init_map_iso(vars);
	vars->map.redraw = 1;
}

void	init_map_iso(t_vars *vars)
{
	vars->map.x = 0;
	vars->map.y = 0;
	vars->map.angle_x = 0;
	vars->map.angle_y = 0;
	vars->map.angle_z = 0;
	vars->map.zoom = 1.0;
	vars->map.redraw = 1;
	vars->map.autorotation = 0;
	paste_cpy_to_map(vars);
	if (vars->map.proj == NULL)
		init_proj(vars);
	first_zoom(vars);
	first_translate_iso(vars, -vars->map.zoom * (vars->map.w / 2),
		-vars->map.zoom * (vars->map.h / 2));
	translate_iso(vars, 1920.0 / 4.0, 1080.0 / 3.0);
}

void	draw_render_fast_iso(t_vars *vars)
{
	int	y00;
	int	y0w;
	int	yh0;
	int	yhw;

	y00 = (vars->map.map[0][0].x + vars->map.map[0][0].y) * SIN8;
	y0w = (vars->map.map[0][vars->map.w - 1].x
			+ vars->map.map[0][vars->map.w - 1].y) * SIN8;
	yh0 = (vars->map.map[vars->map.h - 1][0].x
			+ vars->map.map[vars->map.h - 1][0].y) * SIN8;
	yhw = (vars->map.map[vars->map.h - 1][vars->map.w - 1].x
			+ vars->map.map[vars->map.h - 1][vars->map.w - 1].y) * SIN8;
	if (y00 <= y0w && y00 <= yh0)
		draw_render_fast_00hw(vars);
	else if (yh0 <= y00 && yh0 <= yhw)
		draw_render_fast_h00w(vars);
	else if (yhw <= yh0 && yhw <= y0w)
		draw_render_fast_hw00(vars);
	else if (y0w <= yhw && y0w <= y00)
		draw_render_fast_0wh0(vars);
}

void	draw_render_exact_iso(t_vars *vars)
{
	int	y00;
	int	y0w;
	int	yh0;
	int	yhw;

	y00 = (vars->map.map[0][0].x + vars->map.map[0][0].y) * SIN8;
	y0w = (vars->map.map[0][vars->map.w - 1].x
			+ vars->map.map[0][vars->map.w - 1].y) * SIN8;
	yh0 = (vars->map.map[vars->map.h - 1][0].x
			+ vars->map.map[vars->map.h - 1][0].y) * SIN8;
	yhw = (vars->map.map[vars->map.h - 1][vars->map.w - 1].x
			+ vars->map.map[vars->map.h - 1][vars->map.w - 1].y) * SIN8;
	if (y00 <= y0w && y00 <= yh0)
		draw_render_exact_00hw(vars);
	else if (yh0 <= y00 && yh0 <= yhw)
		draw_render_exact_h00w(vars);
	else if (yhw <= yh0 && yhw <= y0w)
		draw_render_exact_hw00(vars);
	else if (y0w <= yhw && y0w <= y00)
		draw_render_exact_0wh0(vars);
}
