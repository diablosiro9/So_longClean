/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking_map2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dojannin <dojannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 09:42:02 by dojannin          #+#    #+#             */
/*   Updated: 2022/11/05 15:09:29 by dojannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	first_test(char **map)
{
	if (map_is_correct(map) == 0)
		return ;
	if (map_is_oblong(map) == 0)
		ft_error("Error: Map isn't an oblong. Use Google trad. if you need.\n");
	if (map_is_close(map) == 0)
		ft_error("Error: Map isn't close.\n");
	if (doublon(map, 'E', return_pos(map, 'E')) == 0)
		ft_error("Error: WTF. Two or more exit. Don't fool me.\n");
	if (doublon(map, 'P', return_pos(map, 'P')) == 0)
		ft_error("Error: Stop trying shit.\
			Two or more character(s). Ain't multi here idiots.\n");
}

int	checking_map_is_playable(t_play *play)
{
	t_point	data;
	int		i;
	int		j;

	j = 0;
	i = 0;
	data = return_pos(play->map, 'E');
	data = return_pos(play->map, 'E');
	first_test(play->map);
	if (data.x == 5000)
		ft_error("Error: No exit. Can't be finished.\n");
	data = return_pos(play->map, 'P');
	if (data.x == 5000)
		ft_error("Error: No player. Can't playing.\n");
	data = return_pos(play->map, 'C');
	if (data.x == 5000)
		ft_error("Error: No items. Can't collect any items and finished.\n");
	if (int_strlen(play->map[0]) - 1 == max_len_map(play->map))
		ft_error("Error: Map isn't an oblong. Use Google trad. if you need.\n");
	if (map_is_not_split(play) == 0)
		ft_error("Error: Map can't be finished.\n");
	return (1);
}

t_point	*pos_collect(char **map)
{
	t_point	*tab_pos;
	int		i;
	int		j;
	int		index;

	i = 0;
	j = 0;
	index = 0;
	tab_pos = malloc(sizeof(t_point *) * 500);
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
			{
				tab_pos[index].y = i;
				tab_pos[index].x = j;
				index++;
			}
			j++;
		}
		i++;
	}
	return (tab_pos);
}

void	main_split(t_play *play, t_point pos)
{
	char	**tmp;

	tmp = play->map;
	tmp = flood_fill(play->map, (t_point){ft_strlen(play->map[1]),
			max_len_map(play->map)}, (t_point){pos.y, pos.x});
	if (checking_after_fill(play->map) == 0)
		return ;
	if (play->map[pos.y][pos.x] == '0')
	{
		ft_error("Error: Player is locked at starting.\
			Be careful, let him free.\n");
	}
	tmp = flood_fill_reverse(play->map, (t_point){ft_strlen(play->map[1]),
			max_len_map(play->map)}, (t_point){pos.y, pos.x});
}

int	map_is_not_split(t_play *play)
{
	int		i;
	t_point	pos;
	t_point	save;
	t_point	*stock_pos_c;

	i = number_collect(play->map) - 1;
	stock_pos_c = pos_collect(play->map);
	pos = return_pos(play->map, 'P');
	save = return_pos(play->map, 'E');
	play->map[save.y][save.x] = '1';
	play->map[pos.y][pos.x] = '0';
	main_split(play, pos);
	while (i + 1)
	{
		play->map[stock_pos_c[i].y][stock_pos_c[i].x] = 'C';
		i--;
	}
	play->map[pos.y][pos.x] = 'P';
	play->map[save.y][save.x] = 'E';
	free(stock_pos_c);
	return (1);
}
