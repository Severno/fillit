/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_end_spaces.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapril <sapril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 16:00:35 by sapril            #+#    #+#             */
/*   Updated: 2019/09/17 12:35:21 by sapril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_check_end_spaces(const char *s, size_t size)
{
	size_t	i;

	if (size == 0)
		return (0);
	i = size - 1;
	while ((s[i] == ' '
			|| s[i] == ','
			|| s[i] == '\n'
			|| s[i] == '\t')
			&& (int)i != 0)
		i--;
	return (i);
}
