/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   space_operation_iso_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderouba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 15:37:56 by aderouba          #+#    #+#             */
/*   Updated: 2022/11/14 13:59:04 by aderouba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	first_translate_iso(t_vars *vars, float x, float y)
{
	int	i;
	int	j;

	i = 0;
	while (i < vars->map.h)
	{
		j = 0;
		while (j < vars->map.w)
		{
			vars->map.map[i][j].x += x;
			vars->map.map[i][j].y += y;
			j++;
		}
		i++;
	}
	calculate_projection_iso(vars);
	vars->map.redraw = 1;
}

void	translate_iso(t_vars *vars, float x, float y)
{
	int	i;
	int	j;

	vars->map.x += x;
	vars->map.y += y;
	i = -1;
	while (++i < vars->map.h)
	{
		j = -1;
		while (++j < vars->map.w)
		{
			if (x != 0.0)
			{
				vars->map.map[i][j].x += x;
				vars->map.map[i][j].y -= x;
			}
			if (y != 0.0)
			{
				vars->map.map[i][j].x += y;
				vars->map.map[i][j].y += y;
			}
		}
	}
	calculate_projection_iso(vars);
	vars->map.redraw = 1;
}

void	first_zoom(t_vars *vars)
{
	int		i;
	int		j;
	float	zoooooooooom;

	zoooooooooom = 1080.0 / vars->map.w;
	i = 0;
	while (i < vars->map.h)
	{
		j = 0;
		while (j < vars->map.w)
		{
			vars->map.map[i][j].x *= zoooooooooom;
			vars->map.map[i][j].y *= zoooooooooom;
			vars->map.map[i][j].z *= zoooooooooom / 10;
			j++;
		}
		i++;
	}
	vars->map.zoom = zoooooooooom;
}

void	zoom_iso(t_vars *vars, float zoom)
{
	int		i;
	int		j;
	float	tmp_x;
	float	tmp_y;

	tmp_x = vars->map.x;
	tmp_y = vars->map.y;
	translate_iso(vars, -tmp_x, -tmp_y);
	i = 0;
	while (i < vars->map.h)
	{
		j = 0;
		while (j < vars->map.w)
		{
			vars->map.map[i][j].x *= zoom;
			vars->map.map[i][j].y *= zoom;
			vars->map.map[i][j].z *= zoom;
			j++;
		}
		i++;
	}
	translate_iso(vars, tmp_x, tmp_y);
	calculate_projection_iso(vars);
	vars->map.zoom *= zoom;
	vars->map.redraw = 1;
}

void	rotate_iso(t_vars *vars, float angle, char c)
{
	float	tmp_x;
	float	tmp_y;

	tmp_x = vars->map.x;
	tmp_y = vars->map.y;
	translate_iso(vars, -tmp_x, -tmp_y);
	if (c == 'x')
		apply_rotation_x(vars, angle);
	else if (c == 'y')
		apply_rotation_y(vars, angle);
	else if (c == 'z')
		apply_rotation_z(vars, angle);
	translate_iso(vars, tmp_x, tmp_y);
	calculate_projection_iso(vars);
	vars->map.redraw = 1;
}
