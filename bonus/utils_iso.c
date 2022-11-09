/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_iso.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderouba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:07:45 by aderouba          #+#    #+#             */
/*   Updated: 2022/11/09 13:33:02 by aderouba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	key_iso(int keycode, t_vars *vars)
{
	if (keycode == XK_w)
		translate_iso(vars, 0, 10.0);
	else if (keycode == XK_s)
		translate_iso(vars, 0, -10.0);
	else if (keycode == XK_a)
		translate_iso(vars, 10.0, 0);
	else if (keycode == XK_d)
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
	init_proj(vars);
	first_zoom(vars);
	first_translate_iso(vars, -20.0 * (vars->map.w / 2),
		-20.0 * (vars->map.h / 2));
	translate_iso(vars, 1920.0 / 4.0, 1080.0 / 3.0);
}

void	draw_render_iso(t_vars *vars)
{
	int	x;
	int	y;

	if (vars->map.autorotation)
		rotate_iso(vars, 1.0, 'z');
	if (vars->map.redraw)
	{
		clear_screen(vars);
		y = -1;
		while (++y < vars->map.h)
		{
			x = -1;
			while (++x < vars->map.w)
			{
				if (x < vars->map.w - 1)
					draw_line(vars, vars->map.proj[y][x],
						vars->map.proj[y][x + 1]);
				if (y < vars->map.h - 1)
					draw_line(vars, vars->map.proj[y][x],
						vars->map.proj[y + 1][x]);
			}
		}
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
	}
}
