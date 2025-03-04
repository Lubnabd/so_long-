/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labdelkh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 11:42:31 by labdelkh          #+#    #+#             */
/*   Updated: 2025/02/14 11:42:33 by labdelkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(char **map)
{
	int		i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

char	*ft_strdup_rn(const char *str)
{
	size_t	len;
	size_t	i;
	char	*dup;

	len = 0;
	while (str[len] != '\0' && str[len] != '\n' && str[len] != '\r')
		len++;
	dup = (char *)malloc (len + 1);
	if (dup == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		dup[i] = str[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

void	read_fd(int fd)
{
	char	*line;

	line = get_next_line(fd);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}

void	cpy_map(t_cat *cat_game)
{
	int	line_numbers;

	line_numbers = 0;
	cat_game->cpy_map = malloc (sizeof(char *) * (cat_game->y + 1));
	if (!cat_game->cpy_map)
		exit_game(cat_game, 1, "copy map allocation failed");
	cat_game->cpy_map[cat_game->y] = NULL;
	while (line_numbers < cat_game->y)
	{
		cat_game->cpy_map[line_numbers] = ft_strdup
			(cat_game->map[line_numbers]);
		if (!cat_game->cpy_map[line_numbers])
		{
			line_numbers--;
			while (line_numbers >= 0)
			{
				free (cat_game->cpy_map[line_numbers]);
				line_numbers--;
			}
			exit_game(cat_game, 1, "copy map allocation failed");
		}
		line_numbers++;
	}
}
