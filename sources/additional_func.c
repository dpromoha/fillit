/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional_func.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpromoha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 09:01:05 by dpromoha          #+#    #+#             */
/*   Updated: 2019/04/06 09:01:11 by dpromoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	print_tetrx(char **tetrx)
{
	if (!tetrx)
		return ;
	while (*tetrx)
		ft_putendl(*tetrx++);
}

void	free_tetr_arr(char **tetrx)
{
	int i;

	i = 0;
	if (*tetrx || tetrx)
	{
		while (tetrx[i])
			ft_strdel(&tetrx[i++]);
	}
	free(tetrx);
}

void	free_tetri(t_ttr **tet_lst)
{
	int		i;

	i = 0;
	while (*(tet_lst + i))
	{
		free((*(tet_lst + i))->model);
		free(*(tet_lst + i++));
	}
	free(tet_lst);
}

void		put_error(void)
{
	ft_putendl("error");
	exit(1);
}

void		put_usage(void)
{
	ft_putendl("usage: ./fillit file");
	exit(0);
}
