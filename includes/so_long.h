/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dojannin <dojannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 14:44:42 by dojannin          #+#    #+#             */
/*   Updated: 2022/11/05 15:34:46 by dojannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <mlx.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# define WINDOW_LEN 800
# define WINDOW_HEIGHT 600
# define MAP_CRASH	"Error: Map isn't valide.\
Unknown or missing element inside.\n"

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	char	**map;
}t_vars;

typedef struct s_point
{
	int	x;
	int	y;
}t_point;

typedef struct s_data
{
	int		x;
	int		y;
	char	c;
}t_data;

typedef struct s_play
{
	t_vars	*vars;
	char	**map;
	t_point	player;
	t_point	leave;
	void	*exit;
	void	*back;
	void	*img;
	void	*perso;
	void	*left_perso;
	void	*down_perso;
	void	*walk_perso;
	void	*walk_left;
	void	*collec;
	void	*dust;
	void	*bott;
	int		width_exit;
	int		height_exit;
	int		width_back;
	int		height_back;
	int		width_collec;
	int		height_collec;
	int		width_perso;
	int		height_perso;
	int		width_down;
	int		height_down;
	int		width_wl;
	int		height_wl;
	int		width_wp;
	int		height_wp;
	int		width_left;
	int		height_left;
	int		width_dust;
	int		height_dust;
	int		width_bott;
	int		height_bott;
	int		img_width;
	int		img_height;
	int		counter;
	int		direct;
	int		stock;
	char	*string;
}t_play;

// POUR GNL
int		int_strlen(char *s);
int		max_len_map(char **map);
char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s1);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlen(const char *s);
char	*get_next_line(int fd);
char	*make_save(int fd, char *save, char *buffer);
char	**ft_split(char const *s, char c);
// static char	*ligne(char *save);
// static char	*newline(char *save);

int		checking_str(char *str, int hauteur_map);
t_point	return_pos(char **tab, char c);
int		doublon(char **map, char c, t_point pos);
int		map_is_not_split(t_play *play);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		checking_map_is_playable(t_play *play);
void	ft_putstr(char *str);
void	print_map(char **map);
int		is_map(char *str);
void	ft_error(char *msg);
char	**copy_map(char **map, char **copy);
char	*ft_itoa(int n);

//Inputs
void	do_all(t_play *play);
void	ft_putchar(char c);
void	ft_putnbr(int nb);
int		gestion_key_input(t_play *play, int keycode);
void	put_map(t_play *play, char **map, t_vars *vars);
int		checking_moove(t_play *play, t_point save, t_point player, char key);
int		touching_esc(int keycode, t_play *play);
int		help_checking_moove(t_play *play, t_point save, t_point player);

//Map
t_play	*delete_map(t_play *play);
int		complet_collect(char **map, char c);
void	checking_map_line(char *line);
char	**stocking_map(char **map, int fd);
t_play	*start_fill_p(t_play *play, int fd);
t_play	*init2(t_play *play);
t_play	*init_play(t_play *play);
char	**stocking_map(char **map, int fd);
int		checking_str(char *str, int hauteur_map);
t_point	return_pos(char	**tab, char c);
int		map_is_correct(char **map);
int		wall_top_bott(char **map, int i);
int		map_is_close(char **map);
int		map_is_oblong(char **map);
char	**copy_map(char **map, char **copy);
char	**flood_fill_reverse(char **tab, t_point size, t_point begin);
char	**flood_fill(char **tab, t_point size, t_point begin);
char	**filling_reverse(char **tab, char c, t_point size, t_point begin);
char	**filling(char **tab, char c, t_point size, t_point begin);
int		number_collect(char **map);
int		checking_after_fill(char **map);
int		number_collect(char **map);
void	help_put_map_c(t_play *play, t_vars *vars, t_point x_y);
void	main_part(t_play *play, t_vars *vars, t_point x_y, t_point i_j);
void	det_start(t_play *play, t_point i_j, t_point g_start);
void	major_help(t_play *play, t_vars *vars, char **map, t_point *data);
void	finish_func(t_play *play, t_vars *vars, char **map, t_point g_start);
void	help_put_map_p(t_play *play, t_vars *vars, t_point i_j, t_point	x_y);
void	help_finish(t_play *play, char **map, t_vars *vars, t_point g_start);

#endif