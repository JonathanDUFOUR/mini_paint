/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mp_err_msg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 18:34:33 by jodufour          #+#    #+#             */
/*   Updated: 2021/10/03 18:43:53 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "err_msg_lookup.h"

int	mp_err_msg(int const err)
{
	int	i;

	i = 0;
	while (g_err_msg[i].msg && err != g_err_msg[i].err)
		++i;
	if (g_err_msg[i].msg)
		write(1, g_err_msg[i].msg, g_err_msg[i].len);
	return (err);
}
