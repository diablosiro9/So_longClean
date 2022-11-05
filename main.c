/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dojannin <dojannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 14:45:28 by dojannin          #+#    #+#             */
/*   Updated: 2022/11/05 15:36:29 by dojannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

void	checking_map_line(char *line)
{
	int	i;

	i = 0;
	while (line[i] == '\n')
		i++;
	while (line[i] != '\0')
	{
		if (line[i] == '\n' && line[i + 1] == '\n')
		{
			while (line[i] == '\n' && line[i + 1] == '\n')
			{
				if (line[i] == '\n' && line[i + 1] != '\n'
					&& line[i + 1] != '\0')
					ft_error("Error: No man's land on the map.\
						Map can't be played.\n");
				i++;
			}
		}
		i++;
	}
}

void	puterror(int i)
{
	if (i == 500)
	{
		ft_putstr("No map found.\n");
		exit (1);
	}
}

int	main(int ac, char **av)
{
	int			fd;
	t_play		*play;

	fd = 0;
	play = NULL;
	play = init_play(play);
	play = init2(play);
	if (ac != 2)
		ft_error("No map found.\n");
	else
	{
		if (is_map(av[1]) == 1)
		{
			fd = open(av[1], O_RDONLY);
			if (fd < 0)
				ft_error("File doesn't exist.\n");
			if (open(av[1], O_DIRECTORY) > 0)
				ft_error("This is a directory.\n");
			play = start_fill_p(play, fd);
			do_all(play);
		}
	}
	return (0);
}
