/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-d <llopes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 16:57:39 by llopes-d          #+#    #+#             */
/*   Updated: 2024/03/26 20:51:46 by llopes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_memset(void *var, int value, long n)
{
	int				index;
	unsigned char	*temp;

	temp = (unsigned char *)var;
	index = 0;
	while (index < n)
	{
		temp[index] = value;
		index++;
	}
}
