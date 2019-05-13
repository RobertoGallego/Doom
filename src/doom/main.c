/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaporte <llaporte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 14:17:05 by tcourtil          #+#    #+#             */
/*   Updated: 2019/05/08 18:36:30 by llaporte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"
#include "editor.h"

int			get_img_pixel(t_img *img, float x, float y)
{
	int		real_x;
	int		real_y;

	real_x = (int)((img->width - 1) * x);
	real_y = (int)((img->height - 1) * y);
	return (img->data[(img->width * real_y) + real_x]);
}

int			err(const char *msg)
{
	ft_putstr_fd(msg, 0);
	ft_putchar('\n');
	return (1);
}

static int	validmap(char *file)
{
	int l;

	l = ft_strlen(file);
	if (l <= 4)
		return (1);
	if (file[l - 1] != 'p')
		return (1);
	if (file[l - 2] != 'a')
		return (1);
	if (file[l - 3] != 'm')
		return (1);
	if (file[l - 4] != '.')
		return (1);
	return (0);
}

int			audiomixer_init()
{
	// All SDLmixer function work, you just need to 
	// use .wav file, and do not use "music" functions.
	return (0);
}

int			main(int l, char **args)
{
	t_win	win;

	if (l == 3 && (ft_strcmp(args[1], "-e") == 0))
		editor(args[2]);
	else if (l == 2)
	{
		ft_bzero(&win, sizeof(t_win));
		if (validmap(args[1]))
			return (err("The map specified is invalid"));
		if (audiomixer_init())
			return (err("Error initializing audio mixer"));
		if (!init_win(&win, args[1]))
			update(&win);
		clean_wolf(&win);
		free_sdl(&win);
	}
	else
		err("Usage : wolf <path/to/the/map>");
	return (0);
}
