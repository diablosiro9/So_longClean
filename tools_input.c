/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dojannin <dojannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 12:36:11 by dojannin          #+#    #+#             */
/*   Updated: 2022/11/05 14:43:29 by dojannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

int	close_w(int keycode, t_play *play)
{
	(void)keycode;
	mlx_destroy_window(play->vars->mlx, play->vars->win);
	free(play->vars);
	play = delete_map(play);
	free(play);
	exit(0);
}

int	touching_esc(int keycode, t_play *play)
{
	return (close_w(keycode, play));
}

int	help_checking_moove(t_play *play, t_point save, t_point player)
{
	if (play->map[player.y][player.x] == '1')
		return (0);
	else if (play->map[player.y][player.x] == '0'
		|| play->map[player.y][player.x] == 'C')
	{
		play->map[player.y][player.x] = 'P';
		play->map[save.y][save.x] = '0';
		play->player.y = player.y;
		play->player.x = player.x;
		play->counter = play->counter + 1;
		ft_putnbr(play->counter);
		ft_putchar('\n');
	}
	else if (play->map[player.y][player.x] == 'E')
	{
		if (complet_collect(play->map, 'C') == 1)
		{
			delete_map(play);
			ft_putstr("End's Game!\n");
			exit(1);
		}
		else
			return (0);
	}
	return (0);
}
