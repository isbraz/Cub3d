/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 12:00:45 by user              #+#    #+#             */
/*   Updated: 2024/03/29 15:30:45 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stdlib.h>

void	ft_memset(void *var, int value, long n);
void	free_double(char **array);
char	**ft_nsplit(char const *s, char c, size_t n);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char const *s1);
double	get_degree(double radian);
double	get_radian(double degree);
int		ft_strcmp(char *s1, char *s2);
int		ft_strlen(const char *s);
int		ft_atoi(const char *str);
int		ft_isnumeric(char *str);
int		is_floor(char c);
long	time_now(void);

#endif
