/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_ctx.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 18:49:53 by jodufour          #+#    #+#             */
/*   Updated: 2021/10/04 03:56:50 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_CTX_H
# define T_CTX_H

# include <stdio.h>

typedef struct s_ctx	t_ctx;

struct s_ctx
{
	FILE	*stream;
	int		zone_width;
	int		zone_height;
	char	background_char;
	char	*zone;
	size_t	zone_len;
};

int		mp_ctx_init(char const *filename);
int		mp_ctx_zone_fill(void);

void	mp_ctx_clear(void);
void	mp_ctx_zone_print(void);

t_ctx	*mp_ctx_get(void);

#endif
