/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_circle.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 03:00:52 by jodufour          #+#    #+#             */
/*   Updated: 2021/10/04 03:04:24 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_CIRCLE_H
# define T_CIRCLE_H

typedef struct s_circle	t_circle;

struct s_circle
{
	char	type;
	float	x;
	float	y;
	float	radius;
	char	c;
};

#endif
