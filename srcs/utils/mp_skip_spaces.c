/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mp_skip_spaces.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 19:26:48 by jodufour          #+#    #+#             */
/*   Updated: 2021/10/03 19:30:44 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_paint.h"

char	*mp_skip_spaces(char const *str)
{
	while (mp_isspace(*str))
		++str;
	return ((char *)str);
}
