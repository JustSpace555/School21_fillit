/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmebble <qmebble@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 18:29:42 by qmebble           #+#    #+#             */
/*   Updated: 2019/02/16 17:22:42 by oargrave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# define BUFF_SIZE 10

# include "libft/libft.h"
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>

int		main (int argc, char **argv);
t_list	*check(char *buf, t_list *point, int i, int fd);
int		check_buf(char *buf, int i, int sharp, int point);
int		check_tetriminos(char *buf);
t_list	*record(char *buf, t_list *point, char name);
t_list	*record_name(t_list *point);
int		generic_map(t_list *point);
int		ft_sqrt(int nb);
t_list	*ft_list(t_list *point, t_list *start, int siz, int i);
void	ft_list_red(int **ar, char *str, int size);
int		ft_pos(char *map, int start);
int		check_for_fit(char *map, t_list *point, int i);
void	check_first(char *map, int size_map);
char	*ft_alco(t_list *point, int size_map);
int		ft_algorithm(t_list *point, char *map, int pos, int i);
int		*ft_difference(int *coor, int pos, char *map, int len);
char	*new_map(char *map, t_list *point);
void	del(t_list *point, char *map);
t_list	*check_full(int argc, char **argv, t_list *point, int i);

#endif
