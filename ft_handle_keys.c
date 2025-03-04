/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_keys.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labdelkh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 11:44:13 by labdelkh          #+#    #+#             */
/*   Updated: 2025/02/14 11:44:15 by labdelkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_possible_move(t_cat *cat_game, int new_y, int new_x)
{
	if (new_y < 0 || new_y >= cat_game->y || new_x < 0 || new_x >= cat_game->x)
		return (0);
	if (cat_game->map[new_y][new_x] == '1')
		return (0);
	if (cat_game->map[new_y][new_x] == 'E' && cat_game->icecream_num > 0)
	{
		ft_printf("you need to collect all icecreams\n");
		return (0);
	}
	return (1);
}

void	put_player(t_cat *cat_game, char direction)
{
	if (direction == 'L')
		mlx_put_image_to_window(cat_game->mlx, cat_game->win_mlx,
			cat_game->cat_left_img, cat_game->pos_x * WIDTH,
			cat_game->pos_y * HEIGHT);
	else if (direction == 'R')
		mlx_put_image_to_window(cat_game->mlx, cat_game->win_mlx,
			cat_game->cat_right_img, cat_game->pos_x * WIDTH,
			cat_game->pos_y * HEIGHT);
	else if (direction == 'U')
		mlx_put_image_to_window(cat_game->mlx, cat_game->win_mlx,
			cat_game->cat_up_img, cat_game->pos_x * WIDTH,
			cat_game->pos_y * HEIGHT);
	else if (direction == 'D')
		mlx_put_image_to_window(cat_game->mlx, cat_game->win_mlx,
			cat_game->cat_down_img, cat_game->pos_x * WIDTH,
			cat_game->pos_y * HEIGHT);
}

void	move_player(t_cat *cat_game, int new_y, int new_x, char direction)
{
	static int	cat_moves = 0;

	if (is_possible_move(cat_game, new_y, new_x))
	{
		cat_moves++;
		ft_printf("Moves Counter: %d\n", cat_moves);
		if (cat_game->map[new_y][new_x] == 'C')
			cat_game->icecream_num -= 1;
		ft_printf("Icecreams number: %d\n", cat_game->icecream_num);
		if (cat_game->map[new_y][new_x] == 'E')
			exit_game(cat_game, 0, "CAT WON!");
		cat_game->map[cat_game->pos_y][cat_game->pos_x] = '0';
		cat_game->map[new_y][new_x] = 'P';
		mlx_put_image_to_window(cat_game->mlx, cat_game->win_mlx,
			cat_game->floor_img, cat_game->pos_x * WIDTH,
			cat_game->pos_y * HEIGHT);
		cat_game->pos_x = new_x;
		cat_game->pos_y = new_y;
		put_player(cat_game, direction);
	}
}

void	check_move_cat(t_cat *cat_game, int new_y, int new_x, int key_code)
{
	if (key_code == XK_Escape)
		close_window(cat_game);
	else if (key_code == XK_Left || key_code == XK_a)
	{
		new_x--;
		move_player(cat_game, new_y, new_x, 'L');
	}
	else if (key_code == XK_Right || key_code == XK_d)
	{
		new_x++;
		move_player(cat_game, new_y, new_x, 'R');
	}
	else if (key_code == XK_Up || key_code == XK_w)
	{
		new_y--;
		move_player(cat_game, new_y, new_x, 'U');
	}
	else if (key_code == XK_Down || key_code == XK_s)
	{
		new_y++;
		move_player(cat_game, new_y, new_x, 'D');
	}
}

int	handle_keys(int key_code, t_cat *cat_game)
{
	int	new_y;
	int	new_x;

	new_y = cat_game->pos_y;
	new_x = cat_game->pos_x;
	check_move_cat(cat_game, new_y, new_x, key_code);
	return (0);
}
