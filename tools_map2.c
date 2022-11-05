/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dojannin <dojannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 09:18:53 by dojannin          #+#    #+#             */
/*   Updated: 2022/11/05 09:24:49 by dojannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

t_point	return_pos(char	**tab, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (tab[i] != NULL)
	{
		j = 0;
		while (tab[i][j])
		{
			if (tab[i][j] == c)
				return ((t_point){j, i});
			j++;
		}
		i++;
	}
	return ((t_point){5000, 5000});
}

int	checking_str(char *str, int hauteur_map)
{
	int	i;

	i = 0;
	(void)hauteur_map;
	if (str == NULL)
		return (1);
	if (str[0] != '1' && str[ft_strlen(str) - 1] != '1')
		return (0);
	while (str[i])
	{
		if (str[i] != '1' && str[i] != '0' && str[i] != 'P'
			&& str[i] != 'E' && str[i] != 'C' && str[i] != '\n')
			return (0);
		else
			i++;
	}
	return (1);
}

char	**stocking_map(char **map, int fd)
{
	int		i;
	char	save[2];
	int		size;
	char	*line;

	i = 0;
	size = read(fd, save, 1);
	save[1] = '\0';
	line = ft_strdup(save);
	size = read(fd, save, 1);
	save[1] = '\0';
	while (size > 0)
	{
		line = ft_strjoin(line, save);
		size = read(fd, save, 1);
		save[1] = '\0';
	}
	checking_map_line(line);
	map = ft_split(line, '\n');
	free(line);
	return (map);
}
