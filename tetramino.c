/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetramino.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapril <sapril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 13:35:20 by sapril            #+#    #+#             */
/*   Updated: 2019/10/07 10:32:01 by sapril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void			add_back_tetra_el(t_tetra_el *begin_tetra_list,
									t_tetra_info *tetra_info)
{
	t_tetra_el *ptr;

	ptr = begin_tetra_list;
	while (ptr != NULL)
	{
		if (ptr->next == NULL)
		{
			ptr->next = create_tetra_el(tetra_info);
			return ;
		}
		ptr = ptr->next;
	}
}

t_tetra_info	*create_tetra_info(int *x, int *y, char sign)
{
	t_tetra_info	*new_tetra_info;
	int				i;

	if (!(new_tetra_info = (t_tetra_info*)ft_memalloc(
			sizeof(new_tetra_info) +
			sizeof(x) +
			sizeof(y) +
			sizeof(sign))))
		return (NULL);
	if (!(new_tetra_info->x = ft_memalloc(sizeof(int) * 4)) ||
		!(new_tetra_info->y = ft_memalloc(sizeof(int) * 4)))
		return (NULL);
	i = 0;
	while (i < CHARS_NUMBER)
	{
		new_tetra_info->x[i] = x[i];
		new_tetra_info->y[i] = y[i];
		i++;
	}
	new_tetra_info->sign = sign;
	return (new_tetra_info);
}

t_tetra_el		*create_tetra_el(t_tetra_info *tetra_info)
{
	t_tetra_el *new_tetra_el;

	if (!(new_tetra_el = (t_tetra_el*)ft_memalloc(
			sizeof(new_tetra_el) +
			sizeof(tetra_info->y) +
			sizeof(tetra_info->x) +
			sizeof(tetra_info->sign))))
		return (NULL);
	new_tetra_el->figure = tetra_info;
	new_tetra_el->next = NULL;
	return (new_tetra_el);
}

void			free_tetras(t_tetra_el *begin_tetra)
{
	t_tetra_el *tmp;

	while (begin_tetra != NULL)
	{
		tmp = begin_tetra;
		begin_tetra = begin_tetra->next;
		free(tmp->figure->x);
		free(tmp->figure->y);
		free(tmp->figure);
		free(tmp);
	}
}
