/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_iso_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderouba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:07:45 by aderouba          #+#    #+#             */
/*   Updated: 2022/11/11 09:33:36 by aderouba         ###   ########.fr       */
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
