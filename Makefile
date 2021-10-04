# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/03 18:27:01 by jodufour          #+#    #+#              #
#    Updated: 2021/10/04 03:56:09 by jodufour         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

######################################
#              COMMANDS              #
######################################
CC		=	clang -c -o
LINK	=	clang -o
MKDIR	=	mkdir -p
RM		=	rm -rf

######################################
#             EXECUTABLE             #
######################################
NAME	=	mini_paint

#######################################
#             DIRECTORIES             #
#######################################
SRC_DIR	=	srcs/
OBJ_DIR	=	objs/
PRV_DIR	=	private/

#######################################
#              LIBRARIES              #
#######################################

######################################
#            SOURCE FILES            #
######################################
SRC		=	\
			${addprefix ctx/,						\
				${addprefix zone/,					\
					mp_ctx_zone_fill_circle_empty.c	\
					mp_ctx_zone_fill_circle_full.c	\
					mp_ctx_zone_fill.c				\
					mp_ctx_zone_print.c				\
				}									\
				mp_ctx_clear.c						\
				mp_ctx_get.c						\
				mp_ctx_init.c						\
			}										\
			${addprefix utils/,						\
				mp_isdigit.c						\
				mp_isspace.c						\
				mp_line_len.c						\
				mp_memdel.c							\
				mp_skip_float.c						\
				mp_skip_integer.c					\
				mp_skip_spaces.c					\
				mp_strchr.c							\
				mp_strjoin.c						\
				mp_strlen.c							\
			}										\
			main.c									\
			mp_err_msg.c							\
			mp_file_content_check.c					\
			mp_file_content_get.c

######################################
#            OBJECT FILES            #
######################################
OBJ		=	${SRC:.c=.o}
OBJ		:=	${addprefix ${OBJ_DIR}, ${OBJ}}

DEP		=	${OBJ:.o=.d}

#######################################
#                FLAGS                #
#######################################
CFLAGS	=	-Wall -Wextra #-Werror
CFLAGS	+=	-MMD -MP
CFLAGS	+=	-I${PRV_DIR}

LDFLAGS	=	-lm

ifeq (${DEBUG}, 1)
	CFLAGS	+=	-g
endif

#######################################
#                RULES                #
#######################################
${NAME}:	${OBJ}
	${LINK} $@ $^ ${LDFLAGS}

all:	${NAME}

-include ${DEP}

${OBJ_DIR}%.o:	${SRC_DIR}%.c
	@${MKDIR} ${@D}
	${CC} $@ ${CFLAGS} $<

clean:
	${RM} ${OBJ_DIR}

fclean:
	${RM} ${OBJ_DIR} ${NAME}

re:	fclean all

-include /home/jodufour/Templates/mk_files/coffee.mk
-include /home/jodufour/Templates/mk_files/norm.mk

.PHONY:	all clean fclean re coffee norm
