/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zone_fill_lookup.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 03:12:55 by jodufour          #+#    #+#             */
/*   Updated: 2021/10/04 03:18:34 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZONE_FILL_LOOKUP_H
# define ZONE_FILL_LOOKUP_H

# include <stddef.h>
# include "type/t_circle.h"

typedef struct s_fill	t_fill;

struct s_fill
{
	char const	type;
	int			(*f)(t_circle circle);
};

int	mp_ctx_zone_fill_circle_empty(t_circle circle);
int	mp_ctx_zone_fill_circle_full(t_circle circle);

static t_fill const		g_fill[] = {
	{'c', mp_ctx_zone_fill_circle_empty},
	{'C', mp_ctx_zone_fill_circle_full},
	{0, NULL}
};

#endif
