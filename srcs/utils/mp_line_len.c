/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mp_line_len.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 01:39:13 by jodufour          #+#    #+#             */
/*   Updated: 2021/10/04 01:40:24 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	mp_line_len(char const *str)
{
	register char const	*ptr = str;

	while (*ptr && *ptr != '\n')
		++ptr;
	return (ptr - str);
}
