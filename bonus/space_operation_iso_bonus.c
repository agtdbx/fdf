/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   space_operation_iso_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderouba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 15:37:56 by aderouba          #+#    #+#             */
/*   Updated: 2022/11/09 09:41:53 by aderouba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	first_translate_iso(t_vars *vars, double x, double y)
{
	int	i;
	int	j;

	i = 0;
	while (i < vars->map_h)
	{
		j = 0;
		while (j < vars->map_w)
		{
			vars->map[i][j].x += x;
			vars->map[i][j].y += y;
			j++;
		}
		i++;
	}
	calculate_projection_iso(vars);
	vars->redraw = 1;
}

void	translate_iso(t_vars *vars, double x, double y)
{
	int	i;
	int	j;

	vars->x += x;
	vars->y += y;
	i = 0;
	while (i < vars->map_h)
	{
		j = 0;
		while (j < vars->map_w)
		{
			if (x != 0.0)
			{
				vars->map[i][j].x += x;
				vars->map[i][j].y -= x;
			}
			if (y != 0.0)
			{
				vars->map[i][j].x += y;
				vars->map[i][j].y += y;
			}
			j++;
		}
		i++;
	}
	calculate_projection_iso(vars);
	vars->redraw = 1;
}

void	first_zoom(t_vars *vars)
{
	int		i;
	int		j;

	i = 0;
	while (i < vars->map_h)
	{
		j = 0;
		while (j < vars->map_w)
		{
			vars->map[i][j].x *= 20;
			vars->map[i][j].y *= 20;
			vars->map[i][j].z *= 2;
			j++;
		}
		i++;
	}
	vars->zoom = 1.0;
	vars->redraw = 1;
}
#include <stdio.h>
void	zoom_iso(t_vars *vars, double zoom, int x, int y)
{
	int		i;
	int		j;
	double	tmp_x;
	double	tmp_y;

	/*x = (x - vars->proj[vars->map_h / 2][vars->map_w / 2].x);
	y = (y - vars->proj[vars->map_h / 2][vars->map_w / 2].y);*/
	x = vars->map[vars->map_h / 2][vars->map_w / 2].x;
	y = vars->map[vars->map_h / 2][vars->map_w / 2].y;
	//printf("(%i, %i)\n", x, y);
	x = -2;
	y = 0;
	tmp_x = vars->x;
	tmp_y = vars->y;
	translate_iso(vars, -tmp_x, -tmp_y);
	//translate_iso(vars, -10 * x, -10 * y);
	i = 0;
	while (i < vars->map_h)
	{
		j = 0;
		while (j < vars->map_w)
		{
			vars->map[i][j].x *= zoom;
			vars->map[i][j].y *= zoom;
			vars->map[i][j].z *= zoom;
			j++;
		}
		i++;
	}
	//translate_iso(vars, 10 * x, 10 * y);
	translate_iso(vars, tmp_x, tmp_y);
	vars->zoom *= zoom;
	calculate_projection_iso(vars);
	vars->redraw = 1;
}

void	rotate_iso_x(t_vars *vars, double angle)
{
	int		i;
	int		j;
	double	tmp_x;
	double	tmp_y;
	t_point	tmp;

	tmp_x = vars->x;
	tmp_y = vars->y;
	translate_iso(vars, -tmp_x, -tmp_y);
	i = 0;
	while (i < vars->map_h)
	{
		j = 0;
		while (j < vars->map_w)
		{
			tmp.y = vars->map[i][j].y;
			tmp.z = vars->map[i][j].z;
			vars->map[i][j].y = cos(angle * (3.1415 / 180)) * tmp.y + sin(angle * (3.1415 / 180)) * tmp.z;
			vars->map[i][j].z = -sin(angle * (3.1415 / 180)) * tmp.y + cos(angle * (3.1415 / 180)) * tmp.z;
			j++;
		}
		i++;
	}
	translate_iso(vars, tmp_x, tmp_y);
	vars->angle_x += angle;
	calculate_projection_iso(vars);
	vars->redraw = 1;
}

void	rotate_iso_y(t_vars *vars, double angle)
{
	int		i;
	int		j;
	double	tmp_x;
	double	tmp_y;
	t_point	tmp;

	tmp_x = vars->x;
	tmp_y = vars->y;
	translate_iso(vars, -tmp_x, -tmp_y);
	i = 0;
	while (i < vars->map_h)
	{
		j = 0;
		while (j < vars->map_w)
		{
			tmp.x = vars->map[i][j].x;
			tmp.z = vars->map[i][j].z;
			vars->map[i][j].x = cos(angle * (3.1415 / 180)) * tmp.x + sin(angle * (3.1415 / 180)) * tmp.z;
			vars->map[i][j].z = -sin(angle * (3.1415 / 180)) * tmp.x + cos(angle * (3.1415 / 180)) * tmp.z;
			j++;
		}
		i++;
	}
	translate_iso(vars, tmp_x, tmp_y);
	vars->angle_y += angle;
	calculate_projection_iso(vars);
	vars->redraw = 1;
}

void	rotate_iso_z(t_vars *vars, double angle)
{
	int		i;
	int		j;
	double	tmp_x;
	double	tmp_y;
	t_point	tmp;

	tmp_x = vars->x;
	tmp_y = vars->y;
	translate_iso(vars, -tmp_x, -tmp_y);
	i = 0;
	while (i < vars->map_h)
	{
		j = 0;
		while (j < vars->map_w)
		{
			tmp.x = vars->map[i][j].x;
			tmp.y = vars->map[i][j].y;
			vars->map[i][j].x = cos(angle * (3.1415 / 180)) * tmp.x + sin(angle * (3.1415 / 180)) * tmp.y;
			vars->map[i][j].y = -sin(angle * (3.1415 / 180)) * tmp.x + cos(angle * (3.1415 / 180)) * tmp.y;
			j++;
		}
		i++;
	}
	translate_iso(vars, tmp_x, tmp_y);
	vars->angle_z += angle;
	calculate_projection_iso(vars);
	vars->redraw = 1;
}
