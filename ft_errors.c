/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labdelkh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 11:42:40 by labdelkh          #+#    #+#             */
/*   Updated: 2025/02/14 11:42:41 by labdelkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_window(t_cat *cat_game)
{
	exit_game(cat_game, 0, "quit cat_game successful");
	return (0);
}

void	remove_images(t_cat *cat_game)
{
	if (cat_game->cat_down_img)
		mlx_destroy_image(cat_game->mlx, cat_game->cat_down_img);
	if (cat_game->cat_up_img)
		mlx_destroy_image(cat_game->mlx, cat_game->cat_up_img);
	if (cat_game->cat_left_img)
		mlx_destroy_image(cat_game->mlx, cat_game->cat_left_img);
	if (cat_game->cat_right_img)
		mlx_destroy_image(cat_game->mlx, cat_game->cat_right_img);
	if (cat_game->wall_img)
		mlx_destroy_image(cat_game->mlx, cat_game->wall_img);
	if (cat_game->exit_img)
		mlx_destroy_image(cat_game->mlx, cat_game->exit_img);
	if (cat_game->icecream_img)
		mlx_destroy_image(cat_game->mlx, cat_game->icecream_img);
	if (cat_game->floor_img)
		mlx_destroy_image(cat_game->mlx, cat_game->floor_img);
}

void	exit_game(t_cat *cat_game, int exit_code, char *msg)
{
	if (cat_game)
	{
		remove_images(cat_game);
		if (cat_game->map)
			free_map(cat_game->map);
		if (cat_game->cpy_map)
			free_map(cat_game->cpy_map);
		if (cat_game->win_mlx)
			mlx_destroy_window(cat_game->mlx, cat_game->win_mlx);
		if (cat_game->mlx)
		{
			mlx_destroy_display(cat_game->mlx);
			free(cat_game->mlx);
		}
		free(cat_game);
	}
	if (exit_code == 1)
		ft_printf("Error\n%s\n", msg);
	else
		ft_printf("%s\n", msg);
	exit(exit_code);
}
