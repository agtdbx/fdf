/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderouba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 14:00:46 by aderouba          #+#    #+#             */
/*   Updated: 2022/11/04 14:12:04 by aderouba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point	*add_value(t_point *tab, int size, t_point value)
{
	t_point	*new_tab;
	int		i;

	new_tab = malloc(sizeof(t_point) * (size + 1));
	if (new_tab == NULL)
		return (tab);
	i = 0;
	while (i < size)
	{
		new_tab[i] = tab[i];
		i++;
	}
	new_tab[i] = value;
	free(tab);
	return (new_tab);
}

void	add_line(t_vars *vars, t_point *line)
{
	t_point	**new_map;
	int		i;

	i = 0;
	while (vars->map[i] != NULL)
		i++;
	new_map = malloc(sizeof(t_point *) * (i + 2));
	if (new_map == NULL)
		return ;
	i = 0;
	while (vars->map[i] != NULL)
	{
		new_map[i] = vars->map[i];
		i++;
	}
	new_map[i] = line;
	new_map[i + 1] = NULL;
	free(vars->map);
	vars->map = new_map;
	vars->map_h++;
}
