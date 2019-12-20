/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapril <sapril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 15:38:57 by sapril            #+#    #+#             */
/*   Updated: 2019/10/07 07:18:38 by sapril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READ_H
# define READ_H

t_tetra_info		*read_one_block(char *buf, int y_buff[],
									int x_buff[], char sign);
t_tetra_el			*read_input(int fd, char *buf,
		t_tetra_el *begin_tetra);
void				align_figure(int *y_buff, int *x_buff);
void				*is_error(t_tetra_el *begin_tetra);

#endif
