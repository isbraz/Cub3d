/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nsplit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 17:36:06 by llopes-d          #+#    #+#             */
/*   Updated: 2024/02/10 08:04:24 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	ft_strlcpy(char *dst, const char *src, int size)
{
	int	index;
	int	length;

	index = 0;
	length = 0;
	while (src[length])
		length++;
	if (size <= 0)
		return (length);
	while (src[index] && index < (size - 1))
	{
		dst[index] = src[index];
		index++;
	}
	dst[index] = '\0';
	return (length);
}

static char	*free_full_array(char **array, int pos)
{
	if (array[pos] == NULL)
	{
		while (pos > 0)
			free(array[--pos]);
		free(array);
		return (NULL);
	}
	return ("true");
}

static char	**fill_array(char const *s, char c, char **newstr, int n)
{
	size_t	index;	
	size_t	start;
	size_t	word;

	index = 0;
	word = 0;
	while (s[index] == c && s[index] && index < n)
		index++;
	start = index;
	while (s[index] && index < n)
	{
		if ((s[index + 1] == c || s[index + 1] == '\0') && s[index] != c)
		{
			newstr[word] = malloc(((++index - start) + 1) * sizeof(char));
			if (free_full_array(newstr, word) == NULL)
				return (NULL);
			ft_strlcpy(newstr[word++], s + start, (index - start) + 1);
			while (s[index] == c && s[index])
				start = ++index;
		}
		else
			index++;
	}
	return (newstr);
}

char	**ft_nsplit(char const *s, char c, int n)
{
	char	**array;
	int		index;
	int		words;

	index = -1;
	words = 0;
	if (!n)
		return (NULL);
	while (s[++index] && index < n)
		if ((s[index + 1] == c || s[index + 1] == '\0') && s[index] != c)
			words++;
	array = malloc((words + 1) * sizeof(char *));
	if (array == NULL)
		return (NULL);
	array = fill_array(s, c, array, n);
	if (array == NULL)
		return (NULL);
	array[words] = NULL;
	return (array);
}
