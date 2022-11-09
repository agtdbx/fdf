/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   space_rotation_iso_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderouba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 10:52:26 by aderouba          #+#    #+#             */
/*   Updated: 2022/11/09 11:34:53 by aderouba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	apply_rotation_x(t_vars *vars, double angle)
{
	int		i;
	int		j;
	t_point	tmp;

	i = 0;
	while (i < vars->map.h)
	{
		j = 0;
		while (j < vars->map.w)
		{
			tmp.y = vars->map.map[i][j].y;
			tmp.z = vars->map.map[i][j].z;
			vars->map.map[i][j].y = cos(angle * (PI / 180))
				* tmp.y + sin(angle * (PI / 180)) * tmp.z;
			vars->map.map[i][j].z = -sin(angle * (PI / 180))
				* tmp.y + cos(angle * (PI / 180)) * tmp.z;
			j++;
		}
		i++;
	}
	vars->map.angle_x += angle;
}

void	apply_rotation_y(t_vars *vars, double angle)
{
	int		i;
	int		j;
	t_point	tmp;

	i = 0;
	while (i < vars->map.h)
	{
		j = 0;
		while (j < vars->map.w)
		{
			tmp.x = vars->map.map[i][j].x;
			tmp.z = vars->map.map[i][j].z;
			vars->map.map[i][j].x = cos(angle * (PI / 180))
				* tmp.x + sin(angle * (PI / 180)) * tmp.z;
			vars->map.map[i][j].z = -sin(angle * (PI / 180))
				* tmp.x + cos(angle * (PI / 180)) * tmp.z;
			j++;
		}
		i++;
	}
	vars->map.angle_y += angle;
}

void	apply_rotation_z(t_vars *vars, double angle)
{
	int		i;
	int		j;
	t_point	tmp;

	i = 0;
	while (i < vars->map.h)
	{
		j = 0;
		while (j < vars->map.w)
		{
			tmp.x = vars->map.map[i][j].x;
			tmp.y = vars->map.map[i][j].y;
			vars->map.map[i][j].x = cos(angle * (PI / 180))
				* tmp.x + sin(angle * (PI / 180)) * tmp.y;
			vars->map.map[i][j].y = -sin(angle * (PI / 180))
				* tmp.x + cos(angle * (PI / 180)) * tmp.y;
			j++;
		}
		i++;
	}
	vars->map.angle_z += angle;
}

void	rotate_iso(t_vars *vars, double angle, char c)
{
	double	tmp_x;
	double	tmp_y;

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
