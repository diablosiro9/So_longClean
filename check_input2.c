/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dojannin <dojannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 19:10:53 by dojannin          #+#    #+#             */
/*   Updated: 2022/11/05 15:34:31 by dojannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

int	checking_possibility(t_play *play, t_point player, char key)
{
	t_point	futur_pos;
	int		i;

	i = 0;
	futur_pos.x = player.x;
	futur_pos.y = player.y;
	if (key == 'W')
		return (checking_moove(play, player,
				(t_point){futur_pos.x, futur_pos.y - 1}, key));
	else if (key == 'A')
		return (checking_moove(play, player,
				(t_point){futur_pos.x - 1, futur_pos.y}, key));
	else if (key == 'S')
		return (checking_moove(play, player,
				(t_point){futur_pos.x, futur_pos.y + 1}, key));
	else if (key == 'D')
		return (checking_moove(play, player,
				(t_point){futur_pos.x + 1, futur_pos.y}, key));
	else
		return (0);
}

int	checking_moove(t_play *play, t_point save, t_point player, char key)
{
	if (key == 'A')
		play->direct = 1;
	else if (key == 'D')
		play->direct = 0;
	if (play->map[player.y][player.x])
		return (help_checking_moove(play, save, player));
	return (1);
}

int	touching_w(int keycode, t_play *play)
{
	t_point		pos;

	pos = play->player;
	if (keycode == 13 || keycode == 126)
		return (checking_possibility(play, play->player, 'W'));
	else if (keycode == 0 || keycode == 123)
	{
		play->direct = 1;
		return (checking_possibility(play, play->player, 'A'));
	}
	else if (keycode == 1 || keycode == 125)
		return (checking_possibility(play, play->player, 'S'));
	else if (keycode == 2 || keycode == 124)
	{
		play->direct = 0;
		return (checking_possibility(play, play->player, 'D'));
	}
	return (0);
}

int	gestion_key_input(t_play *play, int keycode)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (keycode == 13 || keycode == 126 || keycode == 0 || keycode == 1
		|| keycode == 2 || keycode == 123 || keycode == 124
		|| keycode == 125 || keycode == 53)
	{
		if (keycode == 53)
		{
			ft_putstr("End's Game!\n");
			i = (touching_esc(keycode, play));
			exit(1);
		}
		j = (touching_w(keycode, play));
		put_map(play, play->map, play->vars);
	}
	else
		return (1);
	return (0);
}

void	help_finish(t_play *play, char **map, t_vars *vars, t_point g_start)
{
	int		z;
	char	*string;

	z = 0;
	string = ft_itoa(play->counter);
	if (int_strlen(map[0]) < WINDOW_LEN / 32)
		z = int_strlen(map[0]);
	else
		z = WINDOW_LEN;
	while (g_start.x < z)
	{
		mlx_put_image_to_window(vars->mlx,
			vars->win, play->bott, g_start.x * 32, play->stock * 32);
		g_start.x++;
	}
	mlx_string_put(vars->mlx, vars->win, z / 2,
		play->stock * 32, 0xFFAAFFBB, string);
	free(string);
}
