/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderouba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 17:21:15 by aderouba          #+#    #+#             */
/*   Updated: 2022/11/03 13:27:30 by aderouba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	create_argb(int a, int r, int g, int b)
{
	return (a << 24 | r << 16 | g << 8 | b);
}

// close function
void	mlx_close(t_vars *vars)
{
	if (vars == NULL || vars->mlx == NULL || vars->win == NULL)
		return ;
	mlx_clear_window(vars->mlx, vars->win);
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	free(vars);
	exit(0);
}

// inputs functions
int	event_hook(int keycode, t_vars *vars)
{
	if (keycode == K_ESCAPE || keycode == 79700032)
		mlx_close(vars);
	ft_printf("Keycode : %i\n", keycode);
	return (0);
}

// render function
int	render(t_vars *vars)
{
	(void)vars;
	//ft_printf("coucou\n");
	return (0);
}

// main
int	main(void)
{
	t_vars	*vars;

	vars = malloc(sizeof(t_vars));
	if (vars == NULL)
		return (1);
	// init mlx
	vars->mlx = mlx_init();
	// create window (width, height, name)
	vars->win = mlx_new_window(vars->mlx, 1920, 1080, "FDF");
	// set input functions
	mlx_hook(vars->win, 17, 0, event_hook, vars);
	mlx_key_hook(vars->win, event_hook, vars);
	mlx_mouse_hook(vars->win, event_hook, vars);
	// set render function
	mlx_loop_hook(vars->mlx, render, vars);
	// start mlx loop
	mlx_loop(vars->mlx);

	return (0);
}
