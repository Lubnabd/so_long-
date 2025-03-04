/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labdelkh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 11:43:01 by labdelkh          #+#    #+#             */
/*   Updated: 2025/02/14 11:43:02 by labdelkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include <fcntl.h>
# include <mlx.h>
# include <X11/keysym.h>

# define CAT_DOWN	"sprites/cat_down.xpm"
# define CAT_UP		"sprites/cat_up.xpm"
# define CAT_LEFT	"sprites/cat_left.xpm"
# define CAT_RIGHT	"sprites/cat_right.xpm"
# define FLOOR		"sprites/floor.xpm"
# define ICECREAM	"sprites/collectible.xpm"
# define WALL		"sprites/wall.xpm"
# define EXIT		"sprites/exit.xpm"

# define WIDTH	50
# define HEIGHT	50

typedef struct s_cat
{
	void	*mlx;
	void	*win_mlx;
	void	*cat_down_img;
	void	*cat_up_img;
	void	*cat_right_img;
	void	*cat_left_img;
	void	*wall_img;
	void	*exit_img;
	void	*floor_img;
	void	*icecream_img;
	char	**map;
	char	**cpy_map;
	int		pos_x;				
	int		pos_y;				
	int		x;
	int		y;
	int		players_num;
	int		icecream_num;
	int		exit_num;
	int		did_win;
	int		cpy_icecream_num;
}	t_cat;

typedef struct s_positions
{
	int		y;
	int		x;
}	t_positions;

void	validate_args(int argc, char **argv);
void	check_map_file(char *file_path);
void	set_game_def(t_cat *cat_game);
void	read_map(t_cat *cat_game, char *map);
void	validate_map(t_cat *cat_game);
void	cpy_map(t_cat *cat_game);
void	read_fd(int fd);
char	*ft_strdup_rn(const char *str);
void	set_player_position(t_cat *cat_game);
void	init_game(t_cat *cat_game);
int		handle_keys(int key_code, t_cat *cat_game);
void	free_map(char **map);
int		close_window(t_cat *cat_game);
void	check_solvable(t_cat *cat_game);
void	exit_game(t_cat *cat_game, int exit_code, char *msg);

#endif
