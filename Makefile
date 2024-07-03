# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apodader <apodader@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/16 11:49:18 by apodader          #+#    #+#              #
#    Updated: 2023/02/09 15:11:36 by apodader         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = ft_print_hex.c ft_print_nbr.c ft_print_ptr.c \
	ft_print_str.c ft_print_unsigned.c ft_printf.c \

INCLUDE		=	-I.
	
OBJS = ${SRCS:.c=.o}
DEPS = ${SRCS:.c=.d}

CFLAGS		=	-Wall -Wextra -Werror -g -MMD -MP -MT $@

RM			=	rm -f

CP			=	cp -f

AR			=	ar -rcs

CC			=	gcc

all: make_libs $(NAME)

make_libs:
	$(MAKE) -C libft/

%.o: %.c ft_printf.h
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(NAME): $(OBJS) libft/libft.a
	$(CP) libft/libft.a ./$(NAME)
	$(AR) $(NAME) $(OBJS)

clean:
	${RM} ${OBJS} $(DEPS)
	make clean -C libft/

fclean:	clean
	${RM} ${NAME} $(DEPS)
	make fclean -C libft/

re:		fclean all

.PHONY: 	all clean fclean re