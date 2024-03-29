/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 12:32:37 by user              #+#    #+#             */
/*   Updated: 2024/03/29 12:34:17 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	int	index;

	index = 0;
	while(s1[index] && s2[index])
	{
		if (s1[index] != s2[index])
			return(s1[index] - s2[index]);
		index++;
	}
	return (s1[index] - s2[index]);
}