/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_struct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dojannin <dojannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 09:12:46 by dojannin          #+#    #+#             */
/*   Updated: 2022/11/05 14:43:52 by dojannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

t_play	*init_play(t_play *play)
{
	play = NULL;
	play = malloc(sizeof(t_play));
	play->vars = malloc(sizeof(t_vars));
	play->direct = 0;
	play->img = NULL;
	play->perso = NULL;
	play->width_perso = 0;
	play->height_perso = 0;
	play->exit = NULL;
	play->width_exit = 0;
	play->height_exit = 0;
	play->collec = NULL;
	play->width_collec = 0;
	play->height_collec = 0;
	play->back = NULL;
	play->width_back = 0;
	play->height_back = 0;
	play->walk_perso = NULL;
	play->width_wp = 0;
	play->height_wp = 0;
	play->down_perso = NULL;
	play->width_down = 0;
	play->height_down = 0;
	play->left_perso = NULL;
	return (play);
}

t_play	*init2(t_play *play)
{
	play->width_left = 0;
	play->height_left = 0;
	play->walk_left = NULL;
	play->width_wl = 0;
	play->height_wl = 0;
	play->dust = NULL;
	play->width_dust = 0;
	play->height_dust = 0;
	play->bott = NULL;
	play->map = NULL;
	play->vars->mlx = NULL;
	play->vars->win = NULL;
	play->direct = 0;
	play->string = NULL;
	play->counter = 0;
	return (play);
}

t_play	*start_fill_p(t_play *play, int fd)
{
	play->map = stocking_map(play->map, fd);
	play->player = return_pos(play->map, 'P');
	play->leave = return_pos(play->map, 'E');
	return (play);
}
