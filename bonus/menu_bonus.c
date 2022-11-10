/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderouba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:37:43 by aderouba          #+#    #+#             */
/*   Updated: 2022/11/10 08:34:58 by aderouba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	draw_menu_iso(t_vars *vars, int text_color)
{
	mlx_string_put(vars->mlx, vars->win, 125, 50, text_color, "ISO MODE");
	mlx_string_put(vars->mlx, vars->win, 70, 100, text_color,
		"MOVE UP    -> W or UP");
	mlx_string_put(vars->mlx, vars->win, 70, 125, text_color,
		"MOVE DOWN  -> S or DOWN");
	mlx_string_put(vars->mlx, vars->win, 70, 150, text_color,
		"MOVE LEFT  -> A or LEFT");
	mlx_string_put(vars->mlx, vars->win, 70, 175, text_color,
		"MOVE RIGHT -> D or RIGHT");
	mlx_string_put(vars->mlx, vars->win, 70, 200, text_color,
		"ROTATE X   -> U or I");
	mlx_string_put(vars->mlx, vars->win, 70, 225, text_color,
		"ROTATE Y   -> J or K");
	mlx_string_put(vars->mlx, vars->win, 70, 250, text_color,
		"ROTATE Z   -> N or M");
	mlx_string_put(vars->mlx, vars->win, 64, 275, text_color,
		"AUTO ROTATE -> P");
	mlx_string_put(vars->mlx, vars->win, 46, 300, text_color,
		"GO TO FPS MODE -> SPACE");
}

void	draw_menu(t_vars *vars)
{
	t_pixel	pos;
	int		text_color;

	pos.x = 0;
	pos.y = 0;
	pos.color = create_rgb(50, 50, 50);
	draw_rect(vars, pos, 300, 1080);
	text_color = create_rgb(200, 200, 200);
	mlx_string_put(vars->mlx, vars->win, 140, 25, text_color, "MENU");
	draw_menu_iso(vars, text_color);
	mlx_string_put(vars->mlx, vars->win, 46, 325, text_color,
		"CLOSE MENU     -> TAB");
	mlx_string_put(vars->mlx, vars->win, 70, 350, text_color,
		"EXIT       -> ESCAPE");
}
