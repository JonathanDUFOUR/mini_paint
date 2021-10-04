/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mp_ctx_zone_print.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 02:43:47 by jodufour          #+#    #+#             */
/*   Updated: 2021/10/04 02:47:39 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "type/t_ctx.h"

void	mp_ctx_zone_print(void)
{
	t_ctx *const	ctx = mp_ctx_get();
	int const		zone_width = ctx->zone_width;
	int const		zone_height = ctx->zone_height;
	char const		*zone = ctx->zone;
	int				i;

	i = 0;
	while (i < zone_height)
	{
		write(1, zone, zone_width);
		write(1, "\n", 1);
		zone += zone_width;
		++i;
	}
}
