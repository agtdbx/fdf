/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderouba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:01:39 by aderouba          #+#    #+#             */
/*   Updated: 2022/11/10 09:24:52 by aderouba         ###   ########.fr       */
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
