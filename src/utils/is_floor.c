/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_floor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-d <llopes-d@student.42.fr>           +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 14:42:00 by llopes-d          #+#    #+#             */
/*   Updated: 2024/03/29 15:30:45 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_floor(char c)
{
	if (c == '0' || \
		c == '2' || \
		c == 'N' || \
		c == 'S' || \
		c == 'E' || \
		c == 'W' )
		return (1);
	return (0);
}
