/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mp_skip_integer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 19:31:28 by jodufour          #+#    #+#             */
/*   Updated: 2021/10/03 19:32:17 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_paint.h"

char	*mp_skip_integer(char const *str)
{
	while (mp_isdigit(*str))
		++str;
	return ((char *)str);
}
