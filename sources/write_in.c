/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_in.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpromoha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 09:01:19 by dpromoha          #+#    #+#             */
/*   Updated: 2019/04/06 09:23:50 by dpromoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		x = -1;
static int		y = -1;

int		valid_final_tetrx(int i, int j, char **tetrx, t_ttr *tet_lst)
{
	t_struct	a;

	a.i = 0;
	a.diez = 0;
	init_t_struct(&a);
	if (tet_lst && tetrx)
	{
		while ((tet_lst->model)[a.i] && tetrx[i + a.i])
		{
			a.j = 0;
			while ((tet_lst->model)[a.i][a.j] && tetrx[i + a.i][j + a.j])
			{
				if (!DOTS((tet_lst->model)[a.i][a.j]) &&
					!DOTS(tetrx[i + a.i][j + a.j]))
					return (0);
				else
					HASH((tet_lst->model)[a.i][a.j++]) ? a.diez++ : 0;
			}
			a.i++;
		}
	}
	else
		put_error();
	return (a.diez);
}

int		length_columns(char **tetrx, int i)
{
	t_struct	a;
	int			count;

	i = 0;
	a.j = 0;
	count = 0;
	init_t_struct(&a);
	while (tetrx[i] && MAX_SIZE(i))
	{
		a.j = 0;
		while (tetrx[i][a.j] && MAX_SIZE(a.j))
		{
			if (tetrx[i][a.j] == '#')
			{
				MIN(x) ? x = i : 0;
				count++;
				break ;
			}
			a.j++;
		}
		i++;
	}
	return (count);
}

int		length_rows(char **tetrx, int i)
{
	t_struct	a;
	int			count;

	a.j = 0;
	init_t_struct(&a);
	count = 0;
	while (tetrx[a.j] && MAX_SIZE(a.j))
	{
		i = 0;
		while (tetrx[i] && MAX_SIZE(i))
		{
			if (tetrx[i][a.j] == '#')
			{
				MIN(y) ? y = a.j : 0;
				count++;
				break ;
			}
			i++;
		}
		a.j++;
	}
	return (count);
}

char	**mem_for_new_array(char **new_tetrx, int size)
{
	if (!(new_tetrx = (char**)malloc(sizeof(char*) * (size + 1))))
		free_tetr_arr(new_tetrx);
	else
		new_tetrx[size] = NULL;
	return (new_tetrx);
}

char	**diez_cut_tetrx(char **tetrx, char **new_tetrx, int count)
{
	t_struct	a;
	int			size_c;
	int			size_r;

	a.i = 0;
	init_t_struct(&a);
	M_1(y);
	M_1(x);
	size_c = length_columns(tetrx, count);
	size_r = length_rows(tetrx, count);
	new_tetrx = mem_for_new_array(tetrx, size_c);
	while (length_columns(tetrx, a.i) > a.i)
	{
		a.j = 0;
		new_tetrx[a.i] = ft_strnew(size_r);
		while (length_rows(tetrx, count) > a.j)
			new_tetrx[a.i][a.j++] = tetrx[x][y++];
		M_1(y);
		a.i++;
		x++;
	}
	return (new_tetrx);
}
