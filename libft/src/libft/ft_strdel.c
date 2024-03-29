/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcourtil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 11:34:52 by tcourtil          #+#    #+#             */
/*   Updated: 2018/12/13 12:56:58 by tcourtil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_strdel(char **ap)
{
	if (ap && *ap)
	{
		free(*ap);
		*ap = NULL;
	}
}
