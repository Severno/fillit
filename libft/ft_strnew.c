/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapril <sapril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 18:02:50 by sapril            #+#    #+#             */
/*   Updated: 2019/10/07 12:26:58 by sapril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*new_str;

	if (size + 1 == 0)
		return (NULL);
	if (!(new_str = (char*)malloc(size + 1)))
		return (NULL);
	ft_bzero(new_str, size + 1);
	return (new_str);
}
