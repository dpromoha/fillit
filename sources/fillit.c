/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpromoha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 07:31:30 by dpromoha          #+#    #+#             */
/*   Updated: 2019/04/05 07:34:20 by dpromoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		read_file(char *input, int fd)
{
	char		new_tetrx[21];
	char		**tetrx;
	t_struct	a;
	int			ret;

	a.i = 0;
	if ((fd = open(input, O_RDONLY)) > 0)
	{
		ft_memset(new_tetrx, 0, 21);
		while ((ret = read(fd, &new_tetrx, 20)) > 0)
		{
			new_tetrx[ret] = '\0';
			L_FEED(new_tetrx[0]) ? put_error() : 0;
			tetrx = ft_strsplit(new_tetrx, '\n');
			validation(tetrx) == 1 ? put_error() : 0;
			free_tetr_arr(tetrx);
			ft_memset(new_tetrx, 0, 21);
			a.i++;
			if (read(fd, &new_tetrx, 1))
				!L_FEED(new_tetrx[0]) ? put_error() : 0;
		}
		L_FEED(new_tetrx[0]) ? put_error() : 0;
	}
	return (a.i);
}

int		validation(char **tetrx)
{
	if ((need_elem(tetrx) < 0) || (count_symb(tetrx) < 0))
		return (1);
	else
		return (0);
}

int		fillit(char **tetrx, t_ttr *tet_lst)
{
	t_struct	a;

	a.i = 0;
	a.j = 0;
	while ((tet_lst + a.i)->model)
	{
		if (cross_tetrx(tetrx, (tet_lst + a.i)))
			a.i++;
		else
		{
			M_1((tet_lst + a.i)->i);
			M_1((tet_lst + a.i--)->j);
			if (MIN(a.i) || MIN(a.j))
				return (0);
			else
				put_dots_on_need_place(tet_lst + a.i, tetrx, a.i, a.j);
		}
	}
	return (1);
}

int		main(int ac, char **av)
{
	t_ttr	*tet_lst;
	char	**result;
	int		count;
	int		fd;

	fd = 0;
	if (ac == 2)
	{
		if ((fd = open(av[1], O_RDONLY)) < 0)
			put_error();
		if ((count = read_file(av[1], fd)) < 1)
			put_error();
		if (!(tet_lst = (t_ttr*)malloc(sizeof(t_ttr) * (count + 1))))
			put_error();
		else
			NULL_CHECK((tet_lst + count)->model);
		try_to_set_valid(tet_lst, av[1], fd);
		print_tetrx(result = try_to_set(tet_lst, count));
	}
	else
		put_usage();
	return (1);
}
