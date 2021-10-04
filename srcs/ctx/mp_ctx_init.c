/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mp_ctx_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 02:30:37 by jodufour          #+#    #+#             */
/*   Updated: 2021/10/04 02:50:42 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "type/t_ctx.h"
#include "enum/e_ret.h"

int	mp_ctx_init(char const *filename)
{
	t_ctx *const	ctx = mp_ctx_get();

	ctx->stream = fopen(filename, "r");
	if (!ctx->stream)
		return (FOPEN_ERR);
	fscanf(ctx->stream, "%d %d %c\n",
		&ctx->zone_width,
		&ctx->zone_height,
		&ctx->background_char);
	if (ctx->zone_width < 1 || ctx->zone_width > 300
		|| ctx->zone_height < 1 || ctx->zone_height > 300)
		return (PARSE_ERR);
	ctx->zone_len = ctx->zone_width * ctx->zone_height;
	ctx->zone = malloc((ctx->zone_len + 1) * sizeof(char));
	if (!ctx->zone)
		return (MALLOC_ERR);
	memset(ctx->zone, ctx->background_char, ctx->zone_len);
	ctx->zone[ctx->zone_len] = 0;
	return (SUCCESS);
}
