/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapril <sapril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 15:46:21 by sapril            #+#    #+#             */
/*   Updated: 2019/10/10 19:52:14 by sapril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int				check_map(char *buf)
{
	int i;
	int counter;

	i = 0;
	counter = 0;
	while (i < 19)
	{
		if (buf[i] && buf[i] != '\n' && buf[i] != '#' && buf[i] != '.')
			return (0);
		if (buf[i] == '\n' && ((i + 1) % 5) != 0)
			return (0);
		if (buf[i] == '#')
			counter++;
		i++;
	}
	if (counter != 4 || (!buf[19] || buf[19] != '\n'))
		return (0);
	return (1);
}

int				check_figure(char *buf)
{
	int i;
	int connections;

	i = 0;
	connections = 0;
	while (i < 19)
	{
		if (buf[i] == '#')
		{
			if (i + 1 <= 18 && buf[i + 1] == '#')
				connections++;
			if (i - 1 >= 0 && buf[i - 1] == '#')
				connections++;
			if (i + 5 <= 18 && buf[i + 5] == '#')
				connections++;
			if (i - 5 >= 0 && buf[i - 5] == '#')
				connections++;
		}
		i++;
	}
	return (connections == 6 || connections == 8);
}

static int		count_lines(char *s)
{
	int out;
	int i;

	out = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '\n' && i > 0 && (s[i - 1] == '.' || s[i - 1] == '#'))
			out++;
		i++;
	}
	return (out == 4 || out == 5);
}

int				valid(char *buf)
{
	if (check_figure(buf) && check_map(buf) && count_lines(buf))
		return (1);
	return (0);
}
