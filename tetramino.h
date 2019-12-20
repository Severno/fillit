/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetramino.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapril <sapril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 13:35:28 by sapril            #+#    #+#             */
/*   Updated: 2019/10/07 09:22:45 by sapril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TETRAMINO_H
# define TETRAMINO_H

# define CHARS_NUMBER 4
# define BUFF_SIZE 21

typedef struct			s_tetra_info
{
	int					*x;
	int					*y;
	char				sign;
}						t_tetra_info;

typedef struct			s_tetra_el
{
	int					x_indent;
	int					y_indent;
	struct s_tetra_info	*figure;
	struct s_tetra_el	*next;
}						t_tetra_el;

typedef struct			s_max
{
	int					max_width;
	int					max_height;
}						t_max;

t_tetra_info			*create_tetra_info(int *x, int *y, char sign);
t_tetra_el				*create_tetra_el(t_tetra_info *tetra_info);
void					add_back_tetra_el(t_tetra_el
						*begin_tetra_list, t_tetra_info *tetra_info);
void					free_tetras(t_tetra_el *begin_tetra);

#endif
