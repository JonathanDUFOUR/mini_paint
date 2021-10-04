/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mp_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 01:27:41 by jodufour          #+#    #+#             */
/*   Updated: 2021/10/04 01:43:28 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "mini_paint.h"

char	*mp_strjoin(char const *s0, char const *s1)
{
	char	*output;
	char	*ptr;
	size_t	len;

	len = 0;
	if (s0)
		len = mp_strlen(s0);
	if (s1)
		len += mp_strlen(s1);
	output = malloc((len + 1) * sizeof(char));
	if (!output)
		return (NULL);
	ptr = output;
	while (s0 && *s0)
		*ptr++ = *s0++;
	while (s1 && *s1)
		*ptr++ = *s1++;
	*ptr = 0;
	return (output);
}
