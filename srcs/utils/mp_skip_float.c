/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mp_skip_float.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 19:32:30 by jodufour          #+#    #+#             */
/*   Updated: 2021/10/03 19:33:53 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_paint.h"

char	*mp_skip_float(char const *str)
{
	while (mp_isdigit(*str))
		++str;
	if (*str == '.')
		while (mp_isdigit(*++str))
			continue ;
	return ((char *)str);
}
