/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mp_ctx_zone_fill.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 02:58:44 by jodufour          #+#    #+#             */
/*   Updated: 2021/10/04 03:59:32 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zone_fill_lookup.h"
#include "type/t_ctx.h"
#include "type/t_circle.h"
#include "enum/e_ret.h"

int	mp_ctx_zone_fill(void)
{
	t_ctx *const	ctx = mp_ctx_get();
	t_circle		circle;
	int				ret;
	int				i;

	ret = fscanf(ctx->stream, "%c %f %f %f %c",
			&circle.type, &circle.x, &circle.y, &circle.radius, &circle.c);
	while (ret != EOF)
	{
		i = 0;
		while (g_fill[i].f && circle.type != g_fill[i].type)
			++i;
		if (g_fill[i].f)
		{
			ret = g_fill[i].f(circle);
			if (ret != SUCCESS)
				return (ret);
		}
		ret = fscanf(ctx->stream, "%c %f %f %f %c",
				&circle.type, &circle.x, &circle.y, &circle.radius, &circle.c);
	}
	return (SUCCESS);
}
