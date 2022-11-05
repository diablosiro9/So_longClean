/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dojannin <dojannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 13:51:30 by dojannin          #+#    #+#             */
/*   Updated: 2022/11/05 15:34:16 by dojannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

void	help_put_map_c(t_play *play, t_vars *vars, t_point x_y)
{
	mlx_put_image_to_window(vars->mlx,
		vars->win, play->back, x_y.x, x_y.y);
	mlx_put_image_to_window(vars->mlx,
		vars->win, play->collec, x_y.x, x_y.y);
}

void	mini_help_p(t_play *play, t_vars *vars, t_point i_j, t_point x_y)
{
	if (i_j.y % 2 == 0)
		mlx_put_image_to_window(vars->mlx,
			vars->win, play->left_perso, x_y.x, x_y.y);
	else
		mlx_put_image_to_window(vars->mlx,
			vars->win, play->walk_left, x_y.x, x_y.y);
	mlx_put_image_to_window(vars->mlx,
		vars->win, play->dust, x_y.x + 12, x_y.y);
}

void	help_put_map_p(t_play *play, t_vars *vars, t_point i_j, t_point	x_y)
{
	mlx_put_image_to_window(vars->mlx, vars->win, play->back, x_y.x, x_y.y);
	if (play->direct == 0)
	{
		if (i_j.y % 2 == 0)
			mlx_put_image_to_window(vars->mlx,
				vars->win, play->perso, x_y.x, x_y.y);
		else if (i_j.x % 2 == 0)
			mlx_put_image_to_window(vars->mlx,
				vars->win, play->down_perso, x_y.x, x_y.y);
		else
			mlx_put_image_to_window(vars->mlx,
				vars->win, play->walk_perso, x_y.x, x_y.y);
		mlx_put_image_to_window(vars->mlx,
			vars->win, play->dust, x_y.x - 12, x_y.y);
	}
	else
		mini_help_p(play, vars, i_j, x_y);
}

void	det_start(t_play *play, t_point i_j, t_point g_start)
{
	if (play->player.x >= (WINDOW_LEN / 32) / 2)
	{
		g_start.y = play->player.x - (WINDOW_LEN / 32) / 2;
		i_j.x = 0;
	}
	if (play->player.y >= (WINDOW_HEIGHT / 32) / 2)
		i_j.x = play->player.y - (WINDOW_HEIGHT / 32) / 2;
}

void	finish_func(t_play *play, t_vars *vars, char **map, t_point g_start)
{
	int		z;
	char	*string;

	z = 0;
	string = ft_itoa(play->counter);
	if (int_strlen(map[0]) > max_len_map(map))
		help_finish(play, map, vars, g_start);
	else
	{
		mlx_string_put(vars->mlx, vars->win, 0 * 32,
			0 * 32, 0xFFAAFFBB, string);
		free(string);
	}
}
