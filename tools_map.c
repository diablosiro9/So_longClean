/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dojannin <dojannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 14:36:37 by dojannin          #+#    #+#             */
/*   Updated: 2022/11/05 09:19:19 by dojannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

int	complet_collect(char **map, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == c)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

t_play	*delete_map(t_play *play)
{
	int	i;

	i = max_len_map(play->map);
	while (i > 0)
	{
		free(play->map[i]);
		i--;
	}
	free(play->map[0]);
	play->map = NULL;
	return (play);
}

void	print_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		printf("{%s}\n", map[i]);
		i++;
	}
}

int	is_map(char *str)
{
	int	i;

	i = 0;
	if (str)
	{
		while (i < int_strlen(str) - 4)
			i++;
		if (ft_strncmp(&str[i], ".ber", 4) == 0)
			return (1);
		else
			return (0);
	}
	else
		return (0);
}

int	max_len_map(char **map)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] != '\0')
			j++;
		i++;
	}
	return (i);
}
