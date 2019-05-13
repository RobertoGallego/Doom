/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaporte <llaporte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 17:54:52 by tcourtil          #+#    #+#             */
/*   Updated: 2019/05/08 16:57:01 by llaporte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

int	hook_keys_release(int key, t_win *win)
{
	win->forward = key == 119 ? 0 : win->forward;
	win->back = key == 115 ? 0 : win->back;
	win->jump = key == 49 ? 0 : win->jump;
	win->up = key == 1073741906 ? 0 : win->up;
	win->down = key == 1073741905 ? 0 : win->down;
	win->right = key == 1073741903 ? 0 : win->right;
	win->left = key == 1073741904 ? 0 : win->left;
	win->move_left = key == 97 ? 0 : win->move_left;
	win->action = key == 32 ? 0 : win->action;
	win->move_right = key == 100 ? 0 : win->move_right;
	win->shift = key == 1073742049 ? 0 : win->shift;
	return (0);
}

int	hook_keys_pressed(int key, t_win *win)
{
	ft_printf("%d\n", key);
	if (key == 27)
		win->exit = 1;
	win->debug = key == 18 ? !win->debug : win->debug;
	win->forward = key == 119 ? 1 : win->forward;
	win->back = key == 115 ? 1 : win->back;
	win->jump = key == 49 ? 1 : win->jump;
	win->move_right = key == 100 ? 1 : win->move_right;
	win->move_left = key == 97 ? 1 : win->move_left;
	win->action = key == 32 ? 1 : win->action;
	win->up = key == 1073741906 ? 1 : win->up;
	win->down = key == 1073741905 ? 1 : win->down;
	win->right = key == 1073741903 ? 1 : win->right;
	win->left = key == 1073741904 ? 1 : win->left;
	win->shift = key == 1073742049 ? 1 : win->shift;
	return (0);
}
