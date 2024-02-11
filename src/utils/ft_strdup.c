/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 09:02:24 by user              #+#    #+#             */
/*   Updated: 2024/02/10 09:02:32 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

char	*ft_strdup(char const *s1)
{
	char	*duplicate;
	int		index;
	int		length;

	index = 0;
	length = 0;
	if (!s1)
		return (NULL);
	while (s1[length])
		length++;
	duplicate = malloc(sizeof(char) * (length + 1));
	if (duplicate == NULL)
		return (NULL);
	while (s1[index])
	{
		duplicate[index] = s1[index];
		index++;
	}
	duplicate[index] = '\0';
	return (duplicate);
}