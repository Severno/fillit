/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapril <sapril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 16:05:50 by sapril            #+#    #+#             */
/*   Updated: 2019/09/17 12:35:21 by sapril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		count_words(t_word word)
{
	int word_count;
	int last_space;

	word_count = 0;
	last_space = 1;
	while (*word.str)
	{
		if (!(*word.str == word.c) && last_space)
		{
			word_count++;
			last_space = 0;
		}
		else if (*word.str == word.c)
			last_space = 1;
		word.str++;
	}
	return (word_count);
}

static int		next_word_pos(t_word word)
{
	while (word.str[word.pos] == word.c)
		word.pos++;
	return (word.pos);
}

static int		word_len(t_word word)
{
	int length;
	int pos;

	length = 0;
	pos = word.pos;
	while (!(word.str[pos + length] == word.c
			|| word.str[pos + length] == '\0'))
		length++;
	return (length);
}

static int		set_word(char **res, int n, t_word word)
{
	int length;
	int i;

	word.pos = next_word_pos(word);
	length = word_len(word);
	res[n] = ft_strnew(length + 1);
	i = -1;
	while (++i < length)
		res[n][i] = word.str[word.pos + i];
	res[n][i] = '\0';
	return (word.pos + length);
}

char			**ft_strsplit(char const *str, char c)
{
	t_word	*word;
	int		i;
	int		words;

	if (!str)
		return (NULL);
	if (!(word = (t_word *)malloc(sizeof(t_word))))
		return (NULL);
	word->str = (char *)str;
	word->pos = 0;
	word->c = c;
	words = count_words(*word);
	word->res = (char **)malloc(sizeof(char*) * (words + 1));
	if (!word->res)
		return (NULL);
	i = -1;
	while (++i < words)
		word->pos = set_word(word->res, i, *word);
	word->res[i] = NULL;
	return (word->res);
}
