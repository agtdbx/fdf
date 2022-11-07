/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderouba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 10:56:41 by aderouba          #+#    #+#             */
/*   Updated: 2022/11/07 15:29:28 by aderouba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

t_point	split_element_to_map_point(int x, int y, char *element)
{
	t_point	mp;
	int		i;
	char	*color;

	i = 0;
	while (element[i] != '\0' && element[i] != ',')
		i++;
	if (element[i] == ',')
	{
		color = ft_substr(element, i + 3, 7);
		mp.color = atoi_hex(color, "0123456789abcdef");
		free(color);
	}
	else
		mp.color = create_rgb(255, 255, 255);
	mp.x = x;
	mp.y = y;
	mp.z = atoi(element);
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
		value = split_element_to_map_point(i, vars->map_h, split_result[i]);
		tab = add_value(tab, i, value);
		i++;
	}
	if (vars->map_w == 0)
		vars->map_w = i;
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

	vars->map_w = 0;
	vars->map_h = 0;
	vars->map = malloc(sizeof(int *));
	if (vars->map == NULL)
		return (*vars);
	vars->map[0] = NULL;
	fd = open(argv[1], O_RDWR);
	if (fd == -1)
		return (*vars);
	is_read = get_line(vars, fd);
	while (is_read)
		is_read = get_line(vars, fd);
	return (*vars);
}
