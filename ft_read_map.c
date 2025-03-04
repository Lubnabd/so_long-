/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labdelkh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 11:43:25 by labdelkh          #+#    #+#             */
/*   Updated: 2025/02/14 11:43:26 by labdelkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	read_lines(t_cat *cat_game, char *map, int line_count)
{
	int		fd;
	int		line_number;
	char	*line;

	fd = open(map, O_RDONLY);
	line_number = 0;
	line = get_next_line(fd);
	while (line && line_number < line_count)
	{
		cat_game->map[line_number] = ft_strdup_rn(line);
		free(line);
		line = get_next_line(fd);
		if (!cat_game->map[line_number])
		{
			line_number--;
			while (line_number >= 0)
				free(cat_game->map[line_number--]);
			free(line);
			read_fd(fd);
			exit_game(cat_game, 1, "map allocation failed");
		}
		line_number++;
	}
	close(fd);
}

int	get_lines_num(char *map)
{
	int		counter;
	int		fd;
	char	*line;

	counter = 0;
	fd = open(map, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		counter++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (counter);
}

void	read_map(t_cat *cat_game, char *map)
{
	int	line_numbers;

	line_numbers = get_lines_num(map);
	cat_game->map = malloc(sizeof(char *) * (line_numbers + 1));
	if (!cat_game->map)
		exit_game(cat_game, 1, "map allocation failed");
	cat_game->map[line_numbers] = NULL;
	read_lines(cat_game, map, line_numbers);
	if (!cat_game->map[0])
		exit_game(cat_game, 1, "empty map");
}
