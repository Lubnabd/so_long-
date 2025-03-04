/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labdelkh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 11:42:21 by labdelkh          #+#    #+#             */
/*   Updated: 2025/02/14 11:42:23 by labdelkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_cat(t_cat *cat_game, int w, int h)
{
	cat_game->cat_down_img = mlx_xpm_file_to_image(cat_game->mlx, CAT_DOWN,
			&w, &h);
	if (!cat_game->cat_down_img)
		exit_game(cat_game, 1, "cat down image loading failed");
	cat_game->cat_up_img = mlx_xpm_file_to_image(cat_game->mlx, CAT_UP,
			&w, &h);
	if (!cat_game->cat_up_img)
		exit_game(cat_game, 1, "cat up image loading failed");
	cat_game->cat_left_img = mlx_xpm_file_to_image(cat_game->mlx, CAT_LEFT,
			&w, &h);
	if (!cat_game->cat_left_img)
		exit_game(cat_game, 1, "cat left image loading failed");
	cat_game->cat_right_img = mlx_xpm_file_to_image(cat_game->mlx, CAT_RIGHT,
			&w, &h);
	if (!cat_game->cat_right_img)
		exit_game(cat_game, 1, "cat right image loading failed");
}

void	init_imgs(t_cat *cat_game)
{
	int		w;
	int		h;

	w = WIDTH;
	h = HEIGHT;
	init_cat(cat_game, w, h);
	cat_game->wall_img = mlx_xpm_file_to_image(cat_game->mlx, WALL, &w, &h);
	if (!cat_game->wall_img)
		exit_game(cat_game, 1, "wall image loading failed");
	cat_game->exit_img = mlx_xpm_file_to_image(cat_game->mlx, EXIT, &w, &h);
	if (!cat_game->exit_img)
		exit_game(cat_game, 1, "exit image loading failed");
	cat_game->icecream_img = mlx_xpm_file_to_image(cat_game->mlx, ICECREAM,
			&w, &h);
	if (!cat_game->icecream_img)
		exit_game(cat_game, 1, "icecream image loading failed");
	cat_game->floor_img = mlx_xpm_file_to_image(cat_game->mlx, FLOOR, &w, &h);
	if (!cat_game->floor_img)
		exit_game(cat_game, 1, "floor image loading failed");
}

void	transform(t_cat *cat_game, int i, int j, t_positions positions)
{
	if (cat_game->map[i][j] == '1')
		mlx_put_image_to_window(cat_game->mlx, cat_game->win_mlx,
			cat_game->wall_img, positions.x, positions.y);
	else if (cat_game->map[i][j] == '0')
		mlx_put_image_to_window(cat_game->mlx, cat_game->win_mlx,
			cat_game->floor_img, positions.x, positions.y);
	else if (cat_game->map[i][j] == 'C')
		mlx_put_image_to_window(cat_game->mlx, cat_game->win_mlx,
			cat_game->icecream_img, positions.x, positions.y);
	else if (cat_game->map[i][j] == 'P')
		mlx_put_image_to_window(cat_game->mlx, cat_game->win_mlx,
			cat_game->cat_down_img, positions.x, positions.y);
	else
		mlx_put_image_to_window(cat_game->mlx, cat_game->win_mlx,
			cat_game->exit_img, positions.x, positions.y);
}

void	set_window(t_cat *cat_game)
{
	int			i;
	int			j;
	t_positions	positions;

	i = 0;
	positions.y = 0;
	while (i < cat_game->y)
	{
		j = 0;
		positions.x = 0;
		while (j < cat_game->x)
		{
			transform(cat_game, i, j, positions);
			j++;
			positions.x = positions.x + WIDTH;
		}
		i++;
		positions.y = positions.y + HEIGHT;
	}
}

void	init_game(t_cat *cat_game)
{
	cat_game->mlx = mlx_init();
	if (!cat_game->mlx)
		exit_game(cat_game, 1, "mlx init failed");
	cat_game->win_mlx = mlx_new_window(cat_game->mlx, cat_game->x * WIDTH,
			cat_game->y * HEIGHT, "The Icecream Cat");
	if (!cat_game->win_mlx)
		exit_game(cat_game, 1, "mlx window failed");
	init_imgs(cat_game);
	set_window(cat_game);
}
