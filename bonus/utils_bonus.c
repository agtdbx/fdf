/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderouba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:01:39 by aderouba          #+#    #+#             */
/*   Updated: 2022/11/14 10:14:39 by aderouba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	free_map(t_vars *vars)
{
	int	i;

	i = 0;
	while (i < vars->map.h)
	{
		free(vars->map.map[i]);
		i++;
	}
	free(vars->map.map);
}

void	free_vars(t_vars *vars)
{
	int	i;

	i = 0;
	while (i < vars->map.h)
	{
		free(vars->map.cpymap[i]);
		i++;
	}
	free(vars->map.cpymap);
	free_map(vars);
	i = 0;
	while (i < vars->map.h)
	{
		free(vars->map.proj[i]);
		i++;
	}
	free(vars->map.proj);
}

void	paste_cpy_to_map(t_vars *vars)
{
	int		x;
	int		y;

	vars->map.map = malloc(sizeof(t_point *) * vars->map.h);
	if (vars->map.map == NULL)
		return ;
	y = 0;
	while (y < vars->map.h)
	{
		vars->map.map[y] = malloc(sizeof(t_point) * vars->map.w);
		if (vars->map.map[y] == NULL)
			free_map(vars);
		x = 0;
		while (x < vars->map.w)
		{
			vars->map.map[y][x] = vars->map.cpymap[y][x];
			x++;
		}
		y++;
	}
}

void	draw_hide_behind(t_vars *vars, int pos, int next_y, int next_x)
{
	int		x;
	int		y;
	t_pixel	ps[4];

	y = pos / vars->map.w;
	x = pos % vars->map.w;
	ps[0] = vars->map.proj[y][x];
	ps[1] = vars->map.proj[y][x + next_x];
	ps[2] = vars->map.proj[y + next_y][x + next_x];
	ps[3] = vars->map.proj[y + next_y][x];
	draw_polygon(vars, ps, 4, 0);
}
