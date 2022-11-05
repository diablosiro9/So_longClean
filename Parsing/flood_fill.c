/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dojannin <dojannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 12:21:04 by dojannin          #+#    #+#             */
/*   Updated: 2022/11/05 10:26:18 by dojannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "../includes/so_long.h"

char	**filling(char **tab, char c, t_point size, t_point begin)
{
	if (begin.x < 0 || begin.y < 0 || begin.x >= size.y || begin.y >= size.x)
		return (tab);
	if (tab[begin.x][begin.y] == 'F' || tab[begin.x][begin.y] == '1')
		return (tab);
	tab[begin.x][begin.y] = 'F';
	tab = filling(tab, c, size, (t_point){begin.x - 1, begin.y});
	tab = filling(tab, c, size, (t_point){begin.x + 1, begin.y});
	tab = filling(tab, c, size, (t_point){begin.x, begin.y - 1});
	tab = filling(tab, c, size, (t_point){begin.x, begin.y + 1});
	return (tab);
}

char	**filling_reverse(char **tab, char c, t_point size, t_point begin)
{
	if (begin.x < 0 || begin.y < 0 || begin.x >= size.y || begin.y >= size.x)
		return (tab);
	if (tab[begin.x][begin.y] == '0'
		|| tab[begin.x][begin.y] == '1' || tab[begin.x][begin.y] == 'P')
		return (tab);
	tab[begin.x][begin.y] = '0';
	tab = filling_reverse(tab, c, size, (t_point){begin.x - 1, begin.y});
	tab = filling_reverse(tab, c, size, (t_point){begin.x + 1, begin.y});
	tab = filling_reverse(tab, c, size, (t_point){begin.x, begin.y - 1});
	tab = filling_reverse(tab, c, size, (t_point){begin.x, begin.y + 1});
	return (tab);
}

char	**flood_fill(char **tab, t_point size, t_point begin)
{
	char	c;

	c = tab[begin.x][begin.y];
	tab = filling(tab, c, size, begin);
	return (tab);
}

char	**flood_fill_reverse(char **tab, t_point size, t_point begin)
{
	char	c;

	c = tab[begin.x][begin.y];
	tab = filling_reverse(tab, c, size, begin);
	return (tab);
}

int	checking_after_fill(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C' || map[i][j] == 'E')
				return (0);
			j++;
		}	
		i++;
	}
	return (1);
}
