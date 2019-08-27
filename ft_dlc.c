/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmebble <qmebble@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 23:14:59 by qmebble           #+#    #+#             */
/*   Updated: 2019/02/16 16:26:19 by oargrave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_abs(int a)
{
	if (a < 0)
		return (-1 * a);
	return (a);
}

int		ft_pos(char *map, int start)
{
	while (map[start])
	{
		if (start == 0 && map[start] == '.')
			return (start);
		start++;
		if (map[start] == '.')
			return (start);
	}
	return (0);
}

int		*ft_difference(int *coor, int pos, char *map, int len)
{
	int					i;
	int					difference;
	int					*end;

	if (!(end = (int *)malloc(sizeof(int) * 4)))
		return (0);
	i = 0;
	while (map[len] != '\n')
		len++;
	difference = coor[0] - pos;
	while (i < 4)
	{
		if (i != 0 && (coor[i] - coor[i - 1]) > 1 && len <= 4)
			difference = difference + ft_abs(len - 4);
		else if (i != 0 && (coor[i] - coor[i - 1]) > 1 && len > 4)
			difference = difference - ft_abs(len - 4);
		end[i] = coor[i] - difference;
		i++;
	}
	return (end);
}

void	del(t_list *point, char *map)
{
	t_list	*temp;

	free(map);
	if (!point)
		return ;
	while (point->next)
	{
		free(point->content);
		free((void *)point->content_size);
		temp = point;
		point = point->next;
		free(temp);
	}
	free(point->content);
	free((void *)point->content_size);
	free(point);
}
