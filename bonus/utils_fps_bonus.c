/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_fps_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderouba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 11:58:10 by aderouba          #+#    #+#             */
/*   Updated: 2022/11/10 13:29:01 by aderouba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	reset_fps(t_vars *vars)
{
	free_map(vars);
	init_map_fps(vars);
	vars->map.redraw = 1;
}

void	init_map_fps(t_vars *vars)
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
	translate_fps(vars, 1920.0 / 4, 0.0);
	calculate_projection_fps(vars);
}
