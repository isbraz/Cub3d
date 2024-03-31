/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_now.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-d <llopes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 19:43:16 by llopes-d          #+#    #+#             */
/*   Updated: 2024/03/31 14:10:18 by llopes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>

long	time_now(void)
{
	long int		now;
	struct timeval	time;

	gettimeofday(&time, 0);
	now = (time.tv_sec * 1000 + time.tv_usec / 1000);
	return (now);
}
