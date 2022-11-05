/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dojannin <dojannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 12:29:17 by dojannin          #+#    #+#             */
/*   Updated: 2022/11/05 15:37:05 by dojannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

t_play	*init_img(t_play *play)
{
	play->img = mlx_xpm_file_to_image(play->vars->mlx,
			"Xpm/wall.xpm", &play->img_width, &play->img_height);
	play->perso = mlx_xpm_file_to_image(play->vars->mlx,
			"Xpm/Dude_Monster.xpm", &play->width_perso, &play->height_perso);
	play->exit = mlx_xpm_file_to_image(play->vars->mlx,
			"Xpm/Door.xpm", &play->width_exit, &play->height_exit);
	play->collec = mlx_xpm_file_to_image(play->vars->mlx,
			"Xpm/Monster-Egg.xpm", &play->width_collec, &play->height_collec);
	play->back = mlx_xpm_file_to_image(play->vars->mlx,
			"Xpm/Grass.xpm", &play->width_back, &play->height_back);
	play->walk_perso = mlx_xpm_file_to_image(play->vars->mlx,
			"Xpm/Monster_walk.xpm", &play->width_wp, &play->height_wp);
	play->down_perso = mlx_xpm_file_to_image(play->vars->mlx,
			"Xpm/Monsterdown.xpm", &play->width_down, &play->height_down);
	play->left_perso = mlx_xpm_file_to_image(play->vars->mlx,
			"Xpm/Monsterleft.xpm", &play->width_left, &play->height_left);
	play->walk_left = mlx_xpm_file_to_image(play->vars->mlx,
			"Xpm/WalkLeft.xpm", &play->width_wl, &play->height_wl);
	play->dust = mlx_xpm_file_to_image(play->vars->mlx,
			"Xpm/Dust.xpm", &play->width_dust, &play->height_dust);
	play->bott = mlx_xpm_file_to_image(play->vars->mlx,
			"Xpm/Metal.xpm", &play->width_bott, &play->height_bott);
	return (play);
}

void	put_map(t_play *play, char **map, t_vars *vars)
{
	t_point	g_start;
	t_point	data[2];

	data[0].x = 0;
	data[0].y = 0;
	data[1].x = 0;
	data[1].y = 0;
	g_start.x = 0;
	g_start.y = 0;
	play = init_img(play);
	if (play->player.x >= (WINDOW_LEN / 32) / 2)
	{
		g_start.y = play->player.x - (WINDOW_LEN / 32) / 2;
		data[0].x = 0;
	}
	if (play->player.y >= (WINDOW_HEIGHT / 32) / 2)
		data[0].x = play->player.y - (WINDOW_HEIGHT / 32) / 2;
	play->stock = g_start.y;
	major_help(play, vars, map, data);
	play->stock = data[0].x;
	finish_func(play, vars, map, g_start);
}

void	major_help(t_play *play, t_vars *vars, char **map, t_point *data)
{
	while (map[data[0].x])
	{
		data[0].y = play->stock;
		data[1].x = 0;
		while (map[data[0].x][data[0].y])
		{
			main_part(play, vars, data[1], data[0]);
			data[0].y++;
			data[1].x += 32;
		}
		data[0].x++;
		data[1].y += 32;
	}
}

void	main_part(t_play *play, t_vars *vars, t_point x_y, t_point i_j)
{
	if (play->map[i_j.x][i_j.y] == '0')
		mlx_put_image_to_window(vars->mlx, vars->win, play->back, x_y.x, x_y.y);
	else if (play->map[i_j.x][i_j.y] == '1')
		mlx_put_image_to_window (vars->mlx, vars->win, play->img, x_y.x, x_y.y);
	else if (play->map[i_j.x][i_j.y] == 'C')
		help_put_map_c(play, vars, x_y);
	else if (play->map[i_j.x][i_j.y] == 'P')
		help_put_map_p(play, vars, i_j, x_y);
	else if (play->map[i_j.x][i_j.y] == 'E')
	{
		mlx_put_image_to_window(vars->mlx, vars->win, play->back, x_y.x, x_y.y);
		mlx_put_image_to_window(vars->mlx, vars->win, play->exit, x_y.x, x_y.y);
	}
}

void	help_main_part(t_play *play, char **map, t_vars *vars, t_point *data)
{
	while (map[data[0].x][data[0].y])
	{
		main_part(play, vars, data[1], data[0]);
		data[0].y++;
		data[1].x += 32;
	}
	data[0].x++;
	data[1].y += 32;
}
