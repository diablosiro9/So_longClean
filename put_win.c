/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_win.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dojannin <dojannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 08:59:50 by dojannin          #+#    #+#             */
/*   Updated: 2022/11/05 09:53:23 by dojannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

int	key_hook(int keycode, t_play *play)
{
	return (gestion_key_input(play, keycode));
}

int	ft_destroy_windows(t_vars *d)
{
	mlx_destroy_window(d->mlx, d->win);
	ft_error("Closed");
	exit (1);
}

void	keep_open(t_play *play, char **map)
{
	play->vars->mlx = mlx_init();
	play->vars->win = mlx_new_window(play->vars->mlx,
			WINDOW_LEN, WINDOW_HEIGHT, "Hello world!");
	put_map(play, map, play->vars);
	mlx_hook(play->vars->win, 17, 0, ft_destroy_windows, play->vars);
	mlx_key_hook(play->vars->win, key_hook, play);
	mlx_loop(play->vars->mlx);
}

void	do_all(t_play *play)
{
	if (checking_map_is_playable(play) == 0)
		return ;
	keep_open(play, play->map);
}
