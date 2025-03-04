/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_game_def.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labdelkh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 11:44:02 by labdelkh          #+#    #+#             */
/*   Updated: 2025/02/14 11:44:06 by labdelkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_game_def(t_cat *cat_game)
{
	cat_game->mlx = NULL;
	cat_game->win_mlx = NULL;
	cat_game->cat_down_img = NULL;
	cat_game->cat_up_img = NULL;
	cat_game->cat_left_img = NULL;
	cat_game->cat_right_img = NULL;
	cat_game->wall_img = NULL;
	cat_game->floor_img = NULL;
	cat_game->icecream_img = NULL;
	cat_game->exit_img = NULL;
	cat_game->map = NULL;
	cat_game->cpy_map = NULL;
	cat_game->pos_x = 0;
	cat_game->pos_y = 0;
	cat_game->x = 0;
	cat_game->y = 0;
	cat_game->players_num = 0;
	cat_game->icecream_num = 0;
	cat_game->exit_num = 0;
	cat_game->did_win = 0;
	cat_game->cpy_icecream_num = 0;
}
