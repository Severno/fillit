/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapril <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 13:57:01 by sapril            #+#    #+#             */
/*   Updated: 2019/09/17 12:35:21 by sapril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_return(unsigned long long ret, int neg, const char *str)
{
	int count;

	count = 0;
	while (*str <= '1' || *str >= '9')
		str++;
	while (ft_isdigit(*(str + count)))
		count++;
	if (count >= 19)
		return (neg == -1 ? 0 : -1);
	if (ret > 9223372036854775807)
		return (neg == -1 ? 0 : -1);
	else
		return (ret * neg);
}

int			ft_atoi(const char *str)
{
	unsigned long long	ret;
	int					len;
	int					x;
	int					neg;

	neg = 1;
	x = -1;
	len = 0;
	ret = 0;
	while (ft_isspace(*str))
		str++;
	while (str[len])
		len++;
	while (++x <= len)
	{
		if (ft_isdigit(str[x]))
			ret = (ret * 10) + (str[x] - '0');
		else if (x == 0 && (str[x] == '-' || str[x] == '+'))
			neg = str[x] == '-' ? -1 : 1;
		else
			return (get_return(ret, neg, str));
	}
	return (get_return(ret, neg, str));
}
