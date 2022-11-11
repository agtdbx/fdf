/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_fps_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderouba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 11:58:10 by aderouba          #+#    #+#             */
/*   Updated: 2022/11/11 11:15:21 by aderouba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	key_fps(int keycode, t_vars *vars)
{
	if (keycode == XK_w)
		zoom_fps(vars, 1.02);
	else if (keycode == XK_s)
		zoom_fps(vars, 1.0 / 1.02);
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
	vars->cam.x = 0.0;
	vars->cam.y = 0.0;
	vars->cam.angle_x = 0;
	vars->cam.angle_y = 0;
	vars->cam.angle_z = 0;
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
