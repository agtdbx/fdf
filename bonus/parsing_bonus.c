/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderouba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 10:56:41 by aderouba          #+#    #+#             */
/*   Updated: 2022/11/11 14:34:46 by aderouba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

t_point	split_element_to_map_point(int x, int y, char *element)
{
	t_point	mp;
	int		r;
	int		g;
	int		b;

	mp.x = x;
	mp.y = y;
	mp.z = atoi(element);
	r = 255 * (mp.z > 3 && mp.z <= 7) + mp.z * (mp.z > 100);
	g = (200 - mp.z) * (mp.z > 7 && mp.z <= 100) + 100 *(mp.z <= 3) +
		255 * (mp.z > 3 && mp.z <= 7) + mp.z * (mp.z > 100);
	b = (255 - mp.z) * (mp.z <= 3) + mp.z * (mp.z > 100);
	mp.color = create_rgb(r, g, b);
	return (mp);
}

void	parse_line(t_vars *vars, char **split_result)
{
	int		i;
	t_point	value;
	t_point	*tab;

	tab = malloc(sizeof(t_point));
	if (tab == NULL)
		return ;
	i = 0;
	while (split_result[i] != NULL)
	{
		value = split_element_to_map_point(i, vars->map.h, split_result[i]);
		tab = add_value(tab, i, value);
		i++;
	}
	if (vars->map.w == 0)
		vars->map.w = i;
	add_line(vars, tab);
}

int	get_line(t_vars *vars, int fd)
{
	char	*line;
	char	**split_result;
	int		i;

	line = get_next_line(fd);
	if (line == NULL)
		return (0);
	split_result = ft_split(line, ' ');
	if (split_result == NULL)
	{
		free(line);
		return (0);
	}
	parse_line(vars, split_result);
	i = 0;
	while (split_result[i] != NULL)
	{
		free(split_result[i]);
		i++;
	}
	free(split_result);
	free(line);
	return (1);
}

t_vars	get_map_from_agr(t_vars *vars, char **argv)
{
	int	fd;
	int	is_read;

	vars->map.w = 0;
	vars->map.h = 0;
	vars->map.cpymap = malloc(sizeof(int *));
	if (vars->map.cpymap == NULL)
		return (*vars);
	vars->map.cpymap[0] = NULL;
	fd = open(argv[1], O_RDWR);
	if (fd == -1)
		return (*vars);
	is_read = get_line(vars, fd);
	while (is_read)
		is_read = get_line(vars, fd);
	return (*vars);
}
