/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameloop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaporte <llaporte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 15:01:01 by tcourtil          #+#    #+#             */
/*   Updated: 2019/05/06 02:18:29 by llaporte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

int				game_loop(t_win *win)
{
	if (win->forward)
		up(win);
	if (win->back)
		down(win);
	if (win->move_right)
		straff(win, -1);
	if (win->move_left)
		straff(win, 1);
	if (win->action && win->player.action)
	{
		action(win);
		win->player.action = 0;
	}
	if (!win->action && !win->player.action)
		win->player.action = 1;
	if (win->player.giletjaune > 0)
		win->player.giletjaune--;
	return (0);
}

void			mouse_movements(t_win *win, SDL_MouseMotionEvent motion)
{
	if (motion.xrel)
		win->world->cam->rot += motion.xrel * (M_PI / 1500.0);
	if (motion.yrel)
		win->world->cam->ry -= motion.yrel * (M_PI / 2.0);
	if (win->world->cam->ry > 390)
		win->world->cam->ry = 390;
	if (win->world->cam->ry < -210)
		win->world->cam->ry = -210;
}
