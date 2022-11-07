/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderouba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 17:21:15 by aderouba          #+#    #+#             */
/*   Updated: 2022/11/07 11:27:40 by aderouba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_vars(t_vars *vars)
{
	int	i;

	i = 0;
	while (i < vars->map_h)
	{
		free(vars->map[i]);
		i++;
	}
	free(vars->map);
	i = 0;
	while (i < vars->map_h)
	{
		free(vars->proj[i]);
		i++;
	}
	free(vars->proj);
}

// close function
int	mlx_close(t_vars *vars)
{
	mlx_destroy_image(vars->mlx, vars->img.img);
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	free_vars(vars);
	free(vars->mlx);
	exit(0);
}

void	clear_image(t_vars *vars)
{
	t_pixel	pa;
	t_pixel	pb;
	int		y;

	y = 0;
	pa.x = 0;
	pa.color = 0;
	pb.x = 1920;
	pb.color = 0;
	while (y < 1080)
	{
		pa.y = y;
		pb.y = y;
		draw_line(vars, pa, pb);
		y++;
	}
}

#include <stdio.h>
// inputs functions
int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == XK_Escape)
		mlx_close(vars);
	else if (keycode == XK_Up)
	{
		vars->y += 10.0;
		calculate_projection(vars);
		clear_image(vars);
	}
	else if (keycode == XK_Down)
	{
		vars->y -= 10.0;
		calculate_projection(vars);
		clear_image(vars);
	}
	else if (keycode == XK_Left)
	{
		vars->x += 10.0;
		calculate_projection(vars);
		clear_image(vars);
	}
	else if (keycode == XK_Right)
	{
		vars->x -= 10.0;
		calculate_projection(vars);
		clear_image(vars);
	}
	return (0);
}

int	mouse_hook(int mousecode, int x, int y, t_vars *vars)
{
	(void)x;
	(void)y;
	if (mousecode == 4)
	{
		vars->zoom += 1;
		calculate_projection(vars);
		clear_image(vars);
	}
	if (mousecode == 5)
	{
		vars->zoom -= 1;
		calculate_projection(vars);
		clear_image(vars);
	}
	return (0);
}

// render function
int	render(t_vars *vars)
{
	int	x;
	int	y;

	y = 0;
	while (y < vars->map_h)
	{
		x = 0;
		while (x < vars->map_w)
		{
			if (x < vars->map_w - 1)
				draw_line(vars, vars->proj[y][x], vars->proj[y][x + 1]);
			if (y < vars->map_h - 1)
				draw_line(vars, vars->proj[y][x], vars->proj[y + 1][x]);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
	return (0);
}

// main
int	main(int argc, char **argv)
{
	t_vars	vars;

	if (argc != 2)
		return (1);
	vars = get_map_from_agr(&vars, argv);
	vars.angle = 0.786;
	vars.zoom = 20.0;
	init_proj(&vars);
	calculate_projection(&vars);
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "FDF");
	vars.img.img = mlx_new_image(vars.mlx, 1920, 1080);
	vars.img.addr = mlx_get_data_addr(vars.img.img, &vars.img.bits_per_pixel,
			&vars.img.line_length, &vars.img.endian);
	mlx_hook(vars.win, DestroyNotify, StructureNotifyMask, mlx_close, &vars);
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_mouse_hook(vars.win, mouse_hook, &vars);
	mlx_loop_hook(vars.mlx, render, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
