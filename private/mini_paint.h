/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_paint.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 18:29:08 by jodufour          #+#    #+#             */
/*   Updated: 2021/10/04 02:13:16 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_PAINT_H
# define MINI_PAINT_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4096
# endif

# include <stdio.h>
# include <stddef.h>
# include <stdbool.h>

int		mp_err_msg(int const err);
int		mp_file_content_check(char const *filename);

void	mp_memdel(void *addr);

bool	mp_isdigit(char const c);
bool	mp_isspace(char const c);

char	*mp_file_content_get(FILE *stream);
char	*mp_skip_float(char const *str);
char	*mp_skip_integer(char const *str);
char	*mp_skip_spaces(char const *str);
char	*mp_strchr(char const *str, char const c);
char	*mp_strjoin(char const *s0, char const *s1);

size_t	mp_line_len(char const *str);
size_t	mp_strlen(char const *str);

#endif
