# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hawild <hawild@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/29 13:17:51 by hawild            #+#    #+#              #
#    Updated: 2024/01/23 10:33:08 by hawild           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libftprintf.a

SRCS		=	ft_printf.c ft_conversions_1.c ft_conversions_2.c ft_itoa.c

OBJS		=	${SRCS:.c=.o}

CC 			=	cc

RM 			=  rm -f 

CFLAGS		=  -Wall -Wextra -Werror

all:		$(NAME)

$(NAME):		$(OBJS)
						ar rcs $(NAME) $(OBJS)
						
clean:
						$(RM) $(OBJS)

fclean:			clean
						$(RM) $(NAME)
						
re:						fclean all 

.PHONY:			all clean fclean re 