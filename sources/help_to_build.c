/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_to_build.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpromoha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 09:18:22 by dpromoha          #+#    #+#             */
/*   Updated: 2019/04/06 09:19:48 by dpromoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**new_block(char **tetrx, int size)
{
	t_struct	a;
	char		**new_tetrx;

	a.i = 0;
	if (!(new_tetrx = mem_for_new_array(tetrx, size)))
		put_error();
	while (size > a.i)
	{
		a.j = 0;
		if (!(new_tetrx[a.i] = (char*)malloc(sizeof(char) * (size + 1))))
			free_tetr_arr(new_tetrx);
		while (size > a.j)
		{
			new_tetrx[a.i][a.j] = '.';
			a.j++;
		}
		new_tetrx[a.i++][a.j] = '\0';
	}
	return (new_tetrx);
}

void	put_dots_on_need_place(t_ttr *tet_lst, char **tetrx, int i, int j)
{
	i = 0;
	while ((tet_lst->model)[i])
	{
		j = 0;
		while ((tet_lst->model)[i][j] && MAX_SIZE(j))
		{
			if (!(tetrx[tet_lst->i + i][tet_lst->j + j] == tet_lst->mark))
				j++;
			else
				tetrx[tet_lst->i + i][tet_lst->j + j] = '.';
		}
		i++;
	}
}

int		setting_tetrx(char **tetrx, t_ttr *tet_lst, int i, int j)
{
	t_struct	a;

	a.i = 0;
	if (valid_final_tetrx(i, j, tetrx, tet_lst) != 4)
		return (0);
	while ((tet_lst->model)[a.i] && tetrx[a.i])
	{
		a.j = 0;
		while ((tet_lst->model)[a.i][a.j] && tetrx[i + a.i][j + a.j])
		{
			HASH((tet_lst->model)[a.i][a.j]) ? tetrx[i + a.i][j + a.j] =
				tet_lst->mark : 0;
			a.j++;
		}
		a.i++;
	}
	if (tet_lst->i != i || tet_lst->j != j)
	{
		tet_lst->i = i;
		tet_lst->j = j;
	}
	return (1);
}

int		cross_tetrx(char **tetrx, t_ttr *tet_lst)
{
	t_struct	a;

	a.i = 0;
	while (tetrx[a.i] && a.i < 5)
	{
		a.j = 0;
		while (tetrx[a.i][a.j])
		{
			if ((a.j > tet_lst->j && a.i == tet_lst->i)
				|| (a.i > tet_lst->i))
			{
				if (setting_tetrx(tetrx, tet_lst, a.i, a.j))
					return (1);
			}
			a.j++;
		}
		a.i++;
	}
	return (0);
}
