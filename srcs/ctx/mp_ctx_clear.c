/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mp_ctx_clear.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 18:57:01 by jodufour          #+#    #+#             */
/*   Updated: 2021/10/04 02:53:36 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "type/t_ctx.h"

void	mp_ctx_clear(void)
{
	t_ctx *const	ctx = mp_ctx_get();

	if (ctx->stream)
		fclose(ctx->stream);
	free(ctx->zone);
	memset(ctx, 0, sizeof(t_ctx));
}
