/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cntchr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-d <llopes-d@student.42.fr>           +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 17:36:06 by llopes-d          #+#    #+#             */
/*   Updated: 2024/04/06 18:30:45 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_cntchr(const char *str, char c)
{
	int	index;
	int	counter;

	index = 0;
	counter = 0;
	while(str[index])
	{
		if(str[index] == c)
			counter++;
		index++;
	}
	return (counter);
}
