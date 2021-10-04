/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mp_file_content_check.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 19:19:08 by jodufour          #+#    #+#             */
/*   Updated: 2021/10/04 04:05:36 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_paint.h"
#include "line_check_actions_array.h"
#include "enum/e_ret.h"

static int	first_line_check(char const *ptr)
{
	int	i;

	i = 0;
	while (g_action_first_line[i].check && g_action_first_line[i].skip)
	{
		if (!g_action_first_line[i].check(*ptr))
			return (PARSE_ERR);
		ptr = g_action_first_line[i].skip(ptr);
		++i;
	}
	if (!*ptr || (*(ptr + 1) && *(ptr + 1) != '\n'))
		return (PARSE_ERR);
	return (SUCCESS);
}

static int	other_line_check(char const *ptr)
{
	int	i;

	if (!mp_strchr("Cc", *ptr))
		return (PARSE_ERR);
	++ptr;
	i = 0;
	while (g_action_other_line[i].check && g_action_other_line[i].skip)
	{
		if (!g_action_other_line[i].check(*ptr))
			return (PARSE_ERR);
		ptr = g_action_other_line[i].skip(ptr);
		++i;
	}
	if (!*ptr || (*(ptr + 1) && *(ptr + 1) != '\n'))
		return (PARSE_ERR);
	return (SUCCESS);
}

int	mp_file_content_check(char const *filename)
{
	FILE	*stream;
	char	*content;
	char	*ptr;
	int		ret;

	stream = fopen(filename, "r");
	if (!stream)
		return (FOPEN_ERR);
	content = mp_file_content_get(stream);
	fclose(stream);
	if (!content)
		return (FILE_CONTENT_GET_ERR);
	ptr = content;
	ret = SUCCESS;
	while (*ptr && ret == SUCCESS)
	{
		if (ptr == content)
			ret = first_line_check(ptr);
		else
			ret = other_line_check(ptr);
		ptr += mp_line_len(ptr);
		ptr += !!*ptr;
	}
	mp_memdel(&content);
	return (ret);
}
