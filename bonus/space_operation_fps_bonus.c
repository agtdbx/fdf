/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   space_operation_fps_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderouba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 12:01:40 by aderouba          #+#    #+#             */
/*   Updated: 2022/11/11 10:20:38 by aderouba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	translate_fps(t_vars *vars, double x, double y)
{
	int	i;
	int	j;

	vars->map.y += y;
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
	calculate_projection_fps(vars);
	vars->map.redraw = 1;
}

void	zoom_fps(t_vars *vars, double zoom)
{
	int		i;
	int		j;
	double	tmp_x;
	double	tmp_y;

	tmp_x = vars->map.x;
	tmp_y = vars->map.y;
	translate_fps(vars, -tmp_x, -tmp_y);
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
	translate_fps(vars, tmp_x, tmp_y);
	calculate_projection_fps(vars);
	vars->map.zoom *= zoom;
	vars->map.redraw = 1;
}

void	rotate_fps(t_vars *vars, double angle, char c)
{
	double	tmp_x;
	double	tmp_y;

	tmp_x = vars->map.x;
	tmp_y = vars->map.y;
	translate_fps(vars, -tmp_x, -tmp_y);
	if (c == 'x')
		apply_rotation_x(vars, angle);
	else if (c == 'y')
		apply_rotation_y(vars, angle);
	else if (c == 'z')
		apply_rotation_z(vars, angle);
	translate_fps(vars, tmp_x, tmp_y);
	calculate_projection_fps(vars);
	vars->map.redraw = 1;
}
