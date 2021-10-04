/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mp_ctx_zone_fill_circle_full.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 03:53:56 by jodufour          #+#    #+#             */
/*   Updated: 2021/10/04 04:08:25 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdbool.h>
#include "type/t_ctx.h"
#include "type/t_circle.h"
#include "enum/e_ret.h"

static bool	is_valid(t_circle circle, int zone_width, int zone_height)
{
	return (circle.radius > 0
		&& (int)(circle.x - circle.radius) >= 0
		&& (int)(circle.y - circle.radius) >= 0
		&& (int)(circle.x + circle.radius) < zone_width
		&& (int)(circle.y + circle.radius) < zone_height);
}

static bool	is_inside(t_circle circle, int x, int y)
{
	float	x_dist;
	float	y_dist;

	if ((float)x < circle.x)
		x_dist = circle.x - (float)x;
	else
		x_dist = (float)x - circle.x;
	if ((float)y < circle.y)
		y_dist = circle.y - (float)y;
	else
		y_dist = (float)y - circle.y;
	return ((powf(x_dist, 2) + powf(y_dist, 2)) <= powf(circle.radius, 2));
}

int	mp_ctx_zone_fill_circle_full(t_circle circle)
{
	t_ctx *const	ctx = mp_ctx_get();
	char			*zone;
	int				idx;

	if (!is_valid(circle, ctx->zone_width, ctx->zone_height))
		return (PARSE_ERR);
	zone = ctx->zone;
	while (*zone)
	{
		idx = zone - ctx->zone;
		if (is_inside(circle, idx % ctx->zone_width, idx / ctx->zone_width))
			*zone = circle.c;
		++zone;
	}
	return (SUCCESS);
}
