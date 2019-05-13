/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loadmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaporte <llaporte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 14:17:05 by tcourtil          #+#    #+#             */
/*   Updated: 2019/05/06 18:34:31 by llaporte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

static int		valid_binary(int fd)
{
	char *str;

	str = read_str(fd);
	if (ft_strequ(str, "doom_map"))
	{
		free(str);
		return (1);
	}
	free(str);
	return (0);
}

static int		doom_load2(t_win *win, int fd)
{
	if (!(win->gameover = read_img(fd)))
		return (1);
	if (!(win->gamewin = read_img(fd)))
		return (1);
	if (!(win->world = read_world(fd)))
		return (1);
	if (!(win->textures = read_arrayimg(fd)))
		return (1);
	if (!(win->entity = read_arrayent(fd)))
		return (1);
	return (0);
}

int				doom_load(t_win *win, char *file)
{
	int fd;

	if (!file_exist(file))
		return (1);
	fd = open(file, O_RDONLY);
	if (!valid_binary(fd))
		return (1);
	if (!(win->enttexture = read_arrayimg(fd)))
		return (1);
	if (!(win->arial = read_img(fd)))
		return (1);
	if (!(win->uigilet = read_img(fd)))
		return (1);
	if (!(win->floor = read_img(fd)))
		return (1);
	if (!(win->ceil = read_img(fd)))
		return (1);
	return (doom_load2(win, fd));
}
