/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mp_file_content_get.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 01:19:29 by jodufour          #+#    #+#             */
/*   Updated: 2021/10/04 01:32:36 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "mini_paint.h"

char	*mp_file_content_get(FILE *stream)
{
	char	buff[BUFFER_SIZE + 1];
	char	*output;
	char	*tmp;
	size_t	frd;

	output = NULL;
	frd = fread(buff, sizeof(char), BUFFER_SIZE, stream);
	while (frd)
	{
		buff[frd] = 0;
		tmp = output;
		output = mp_strjoin(output, buff);
		mp_memdel(&tmp);
		if (!output)
			return (NULL);
		frd = fread(buff, sizeof(char), BUFFER_SIZE, stream);
	}
	return (output);
}
