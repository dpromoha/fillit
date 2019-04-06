/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetrx.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpromoha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 09:10:14 by dpromoha          #+#    #+#             */
/*   Updated: 2019/04/06 09:13:46 by dpromoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		count_where_to_set(int size, int count)
{
	if (count == 0)
		return (1);
	size = size * 4;
	while (count * count != size)
	{
		if (size < count * count)
		{
			size++;
			count = 1;
		}
		count++;
	}
	return (count);
}

char	**try_to_set(t_ttr *tet_lst, int size)
{
	char	**tetrx;
	int		count;

	tetrx = NULL;
	count = 2;
	tetrx = new_block(tetrx, count_where_to_set(size, count));
	while (!fillit(tetrx, tet_lst))
	{
		count = 2;
		free_tetr_arr(tetrx);
		tetrx = new_block(tetrx, count_where_to_set(size++, count));
	}
	return (tetrx);
}

void	to_letters(t_ttr *tet_lst, char **new_block, int i)
{
	static char	**tetrx = NULL;
	int			count;

	count = 0;
	(tet_lst + i)->model = diez_cut_tetrx(new_block, tetrx, count);
	if (!M_1((tet_lst + i)->i))
		M_1((tet_lst + i)->i);
	free_tetr_arr(new_block);
}

void	try_to_set_valid(t_ttr *tet_lst, char *input, int fd)
{
	t_struct	a;
	char		**tetrx;

	a.i = 0;
	while ((read(fd, input, 20) > 0))
	{
		tetrx = ft_strsplit(input, '\n');
		if (tetrx)
		{
			(tet_lst + a.i)->mark = a.i + 'A';
			to_letters(tet_lst, tetrx, a.i++);
			read(fd, input, 1);
		}
		else if (!tetrx)
			free_tetr_arr(tetrx);
	}
	close(fd);
}
