/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapril <sapril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 08:28:36 by sapril            #+#    #+#             */
/*   Updated: 2019/10/07 13:07:05 by sapril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			solve_map(t_tetra_el *begin_tetra, char **map, int map_size)
{
	t_tetra_el *tmp;

	if (begin_tetra == NULL)
		return (1);
	tmp = begin_tetra;
	tmp->y_indent = 0;
	tmp->x_indent = 0;
	while (check_bound(tmp, map_size, 'y'))
	{
		while (check_bound(tmp, map_size, 'x'))
		{
			if (!is_overlay(map, tmp, map_size))
			{
				place_figure(map, tmp, tmp->figure->sign);
				if (solve_map(tmp->next, map, map_size))
					return (1);
				else
					place_figure(map, tmp, '.');
			}
			tmp->x_indent++;
		}
		tmp->x_indent = 0;
		tmp->y_indent++;
	}
	return (0);
}

int			solve(t_tetra_el *begin_tetra)
{
	char	**map;
	int		map_size;
	int		count_figure;
	t_max	*max_h_w;

	max_h_w = (t_max*)ft_memalloc(sizeof(t_max));
	if ((count_figure = count_figures(begin_tetra, max_h_w)) > 26)
		return (0);
	map_size = get_map_size(count_figure, max_h_w);
	map = create_map(map_size);
	while (!solve_map(begin_tetra, map, map_size))
	{
		free_map(map, map_size);
		map_size++;
		map = create_map(map_size);
	}
	free(max_h_w);
	print_map(map, map_size);
	free_map(map, map_size);
	return (1);
}

void		place_figure(char **map, t_tetra_el *tetra, char sign)
{
	int i;
	int x;
	int y;

	i = 0;
	while (i < 4)
	{
		y = tetra->figure->y[i] + tetra->y_indent;
		x = tetra->figure->x[i] + tetra->x_indent;
		map[y][x] = sign;
		i++;
	}
}

int			is_overlay(char **map, t_tetra_el *tetra, int map_size)
{
	int i;
	int x;
	int y;

	i = 0;
	x = tetra->figure->x[i] + tetra->x_indent;
	y = tetra->figure->y[i] + tetra->y_indent;
	if (x >= map_size || y >= map_size)
		return (0);
	while (i < CHARS_NUMBER && map[y][x] == '.')
	{
		i++;
		x = tetra->figure->x[i] + tetra->x_indent;
		y = tetra->figure->y[i] + tetra->y_indent;
		if (x >= map_size || y >= map_size)
			return (0);
	}
	return (i != 4);
}

int			check_bound(t_tetra_el *tetra, int map_size, char axis)
{
	if (axis == 'x')
		return (tetra->figure->x[0] + tetra->x_indent < map_size
		&& tetra->figure->x[1] + tetra->x_indent < map_size
		&& tetra->figure->x[2] + tetra->x_indent < map_size
		&& tetra->figure->x[3] + tetra->x_indent < map_size);
	else if (axis == 'y')
		return (tetra->figure->y[0] + tetra->y_indent < map_size
		&& tetra->figure->y[1] + tetra->y_indent < map_size
		&& tetra->figure->y[2] + tetra->y_indent < map_size
		&& tetra->figure->y[3] + tetra->y_indent < map_size);
		return (0);
}
