/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mp_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 02:08:59 by jodufour          #+#    #+#             */
/*   Updated: 2021/10/04 02:11:18 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*mp_strchr(char const *str, char const c)
{
	while (*str && *str != c)
		++str;
	if (*str == c)
		return ((char *)str);
	return (NULL);
}
