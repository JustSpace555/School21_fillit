/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmebble <qmebble@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 18:17:07 by qmebble           #+#    #+#             */
/*   Updated: 2019/02/20 19:00:38 by qmebble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	int		i;
	char	*map;
	t_list	*temp;
	t_list	*point;
	t_list	*new;

	i = 0;
	map = NULL;
	point = ft_lstnew("", 0);
	if (!(point = check_full(argc, argv, point, i)))
	{
		ft_putstr("error");
		ft_putchar('\n');
		del(point, map);
		return (0);
	}
	temp = point;
	point = point->next;
	i = generic_map(point);
	new = point;
	point = ft_list(point, new, 0, 0);
	map = ft_alco(point, i);
	ft_putstr(map);
	del(temp, map);
	return (0);
}

t_list	*check_full(int argc, char **argv, t_list *point, int i)
{
	t_list			*new;
	int				fd;
	char			*buf;

	fd = 0;
	if (argc != 2)
		return (NULL);
	if (!(buf = (char *)malloc(sizeof(char) * 23)))
		return (NULL);
	fd = open(argv[1], O_RDONLY);
	if ((fd < 0))
	{
		free(buf);
		return (NULL);
	}
	if (!(new = check(buf, point, i, fd)))
		return (NULL);
	if (!(new = record_name(point)))
		return (NULL);
	return (new);
}

t_list	*ft_list(t_list *point, t_list *start, int size, int i)
{
	int		**ar;
	char	*str;

	while (point)
	{
		size++;
		point = point->next;
	}
	if (!(ar = (int **)malloc(sizeof(int *) * size)))
		return (0);
	point = start;
	while (i != size)
	{
		if (!(ar[i] = (int *)malloc(sizeof(int) * 4)))
			return (0);
		point->content_size = (size_t)ar[i];
		str = point->content;
		ft_list_red(ar, str, i);
		i++;
		if (point->next != NULL)
			point = point->next;
	}
	free(ar);
	return (start);
}

void	ft_list_red(int **ar, char *str, int size)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == '#')
		{
			ar[size][j] = i;
			j++;
		}
		i++;
	}
}
