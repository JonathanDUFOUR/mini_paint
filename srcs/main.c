/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 18:28:34 by jodufour          #+#    #+#             */
/*   Updated: 2021/10/04 04:07:28 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_paint.h"
#include "type/t_ctx.h"
#include "enum/e_ret.h"

int	main(int ac, char **av)
{
	int	ret;

	if (ac != 2)
		return (!!mp_err_msg(AC_ERR));
	ret = mp_file_content_check(av[1]);
	if (ret == SUCCESS)
		ret = mp_ctx_init(av[1]);
	if (ret == SUCCESS)
		ret = mp_ctx_zone_fill();
	if (ret == SUCCESS)
		mp_ctx_zone_print();
	mp_ctx_clear();
	if (ret != SUCCESS)
		return (!!mp_err_msg(ret));
	return (SUCCESS);
}
