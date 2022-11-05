/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dojannin <dojannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 14:34:03 by dojannin          #+#    #+#             */
/*   Updated: 2022/11/05 09:45:28 by dojannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	map_is_correct(char **map)
{
	int	hauteur_map;
	int	i;
	int	j;

	i = 0;
	j = 0;
	hauteur_map = max_len_map(map);
	while (map[i] != NULL)
	{
		if (i != 0 && map[i][0] == '\n')
		{
			ft_error(MAP_CRASH);
		}
		if (checking_str(map[i], hauteur_map) == 0)
		{
			ft_error(MAP_CRASH);
			exit (1);
		}
		i++;
	}
	return (1);
}

int	wall_top_bott(char **map, int i)
{
	int	j;

	j = 0;
	while (map[i][j] != '\0')
	{	
		if (map[i][j] != '1' && map[i][j] != '\n')
			return (0);
		j++;
	}
	return (1);
}

int	map_is_close(char **map)
{
	int	i;
	int	j;
	int	len_size;

	i = 0;
	j = 0;
	len_size = int_strlen(map[0]);
	i = 0;
	while (map[i] != NULL)
	{
		if (i == 0 || i == max_len_map(map) - 1)
		{
			if (wall_top_bott(map, i) == 0)
				return (0);
			else if (i == max_len_map(map))
				return (1);
		}
		if (map[i][j] != '1' || map[i][int_strlen(map[i]) - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	map_is_oblong(char **map)
{
	int	i;
	int	save;

	i = 1;
	save = int_strlen(map[0]);
	while (map[i])
	{
		if (save != int_strlen(map[i]))
			return (0);
		i++;
	}
	return (1);
}

char	**copy_map(char **map, char **copy)
{
	int		i;
	int		j;
	char	**tmp;

	i = 0;
	j = 0;
	tmp = map;
	tmp[0] = ft_strdup(map[0]);
	while (map[i] != NULL)
	{
		while (map[i][j] != '\0' && map[i][j] != '\n')
			j++;
		copy[i] = ft_strdup(map[i]);
		i++;
	}
	return (copy);
}
