/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_tetriminos.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmebble <qmebble@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 10:00:33 by oargrave          #+#    #+#             */
/*   Updated: 2019/02/16 16:24:29 by oargrave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_list	*check(char *buf, t_list *point, int i, int fd)
{
	t_list	*new;
	char	name;

	name = 'A';
	new = point;
	while ((i = read(fd, buf, 21)))
	{
		buf[i] = '\0';
		if ((ft_strlen(buf) != 21 && ft_strlen(buf) != 20))
		{
			free(buf);
			return (NULL);
		}
		if (!(check_buf(buf, 0, 0, 0)) || buf[0] == '\0')
		{
			free(buf);
			return (NULL);
		}
		point = record(buf, point, name);
		name++;
	}
	close(fd);
	free(buf);
	return (point);
}

int		check_buf(char *buf, int i, int sharp, int point)
{
	int			poin;

	poin = 0;
	while (buf[i] != '\0')
	{
		if ((buf[i] != '.' && buf[i] != '#' && buf[i] != '\n') ||
		(buf[i] == '\n' && (i != 4 && i != 9 && i != 14 && i != 19 && i != 20)))
			return (0);
		if (buf[i] == '#')
			sharp++;
		else if (buf[i] == '\n')
			poin++;
		else
			point++;
		i++;
	}
	if (((sharp != 4 || point != 12) && (poin != 4 || poin != 5
					|| poin != 3)) || (!(check_tetriminos(buf))))
		return (0);
	return (1);
}

int		check_tetriminos(char *buf)
{
	int					com;
	int					i;

	com = 0;
	i = 0;
	while (buf[i] != '\0')
	{
		if (buf[i] == '#')
		{
			if (i < 19 && buf[i] && buf[i + 1] == '#')
				com++;
			if (i != 0 && buf[i] && buf[i - 1] == '#')
				com++;
			if (i >= 5 && buf[i] && buf[i - 5] == '#')
				com++;
			if (i < 16 && buf[i] && buf[i + 5] == '#')
				com++;
		}
		i++;
	}
	if (buf[0] == '\0' || com < 6)
		return (0);
	return (1);
}

t_list	*record(char *buf, t_list *point, char name)
{
	t_list		*new;
	int			i;
	char		*str;

	i = ft_strlen(buf);
	new = point;
	while (new)
		new = new->next;
	if (!new)
		new = ft_lstnew("", 0);
	buf[i] = name;
	buf[i + 1] = '\0';
	str = new->content;
	new->content = ft_strsub(buf, 0, i + 1);
	free(str);
	point->next = new;
	return (new);
}

t_list	*record_name(t_list *point)
{
	char				*str;
	t_list				*start;

	start = point;
	while (point->next)
		point = point->next;
	str = point->content;
	if ((str[19] == '\n' && str[20] == '\n') || (str[19] != '\n'))
		return (0);
	return (start);
}
