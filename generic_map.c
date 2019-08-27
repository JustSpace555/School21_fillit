/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generic_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmebble <qmebble@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 18:15:35 by qmebble           #+#    #+#             */
/*   Updated: 2019/02/12 18:16:46 by qmebble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	generic_map(t_list *point)
{
	int index;

	index = 0;
	while (point)
	{
		if ((point = point->next))
			index++;
	}
	return (ft_sqrt(index * 4));
}

int	ft_sqrt(int nb)
{
	int i;

	i = 2;
	if (nb == 0)
		return (1);
	while (i < nb / (i - 1))
	{
		if (((i * i) == nb) || ((i * i) + 1 >= nb))
			return (i);
		i++;
	}
	return (i);
}
