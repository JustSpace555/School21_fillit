/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alco.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmebble <qmebble@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 18:40:48 by qmebble           #+#    #+#             */
/*   Updated: 2019/02/16 15:01:37 by oargrave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	check_first(char *map, int size_map)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (i < (size_map * size_map + size_map))
	{
		if (count == size_map)
		{
			map[i] = '\n';
			count = 0;
		}
		else
		{
			map[i] = '.';
			count++;
		}
		i++;
	}
	map[i] = '\0';
	return ;
}

char	*ft_alco(t_list *point, int size_map)
{
	char	*map;

	if (!(map = (char *)malloc(sizeof(char) *
	(size_map * size_map + (size_map + 1)))))
		return (0);
	check_first(map, size_map);
	if (!(check_for_fit(map, point, size_map)))
	{
		free(map);
		return (ft_alco(point, size_map + 1));
	}
	return (map);
}

int		check_for_fit(char *map, t_list *point, int size_map)
{
	int	pos;

	pos = 0;
	while (pos != size_map * size_map + size_map - 2)
	{
		if (point == NULL)
			return (1);
		if (!(ft_algorithm(point, map, pos, 0)))
		{
			pos++;
			continue ;
		}
		if (point->next == NULL || check_for_fit(map, point->next, size_map))
			return (1);
		else
		{
			new_map(map, point);
			pos++;
		}
	}
	return (0);
}

int		ft_algorithm(t_list *point, char *map, int pos, int i)
{
	int		*coor;
	int		letter;
	char	*name;

	letter = ((ft_strlen(map)) - 1);
	name = (char *)point->content;
	coor = (int *)point->content_size;
	coor = ft_difference(coor, pos, map, 0);
	while (i != 4)
	{
		if (coor[i] > letter || map[coor[i]] != '.')
		{
			free(coor);
			return (0);
		}
		i++;
	}
	i = 0;
	while (i != 4)
	{
		map[coor[i]] = name[ft_strlen(name) - 1];
		i++;
	}
	free(coor);
	return (1);
}

char	*new_map(char *map, t_list *point)
{
	int		i;
	int		count;
	char	*str;
	char	name;

	str = point->content;
	name = str[ft_strlen(str) - 1];
	i = 0;
	count = 0;
	while (count != 4 && map[i] != '\0')
	{
		if (map[i] == name)
		{
			map[i] = '.';
			count++;
		}
		i++;
	}
	return (map);
}
