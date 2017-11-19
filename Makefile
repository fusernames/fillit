# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alcaroff <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/07 15:15:20 by alcaroff          #+#    #+#              #
#    Updated: 2017/11/19 04:28:13 by alcaroff         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	fillit
FLAGS	=	-Wall -Werror -Wextra
SRC		=	$(wildcard *.c)
OBJ		=	$(SRC:.c=.o)
LIBFT	=	../libft/libft.a

all: $(NAME)

$(NAME): $(OBJ)
	gcc $(OBJ) $(LIBFT) -o $(NAME) $(FLAGS) 

%.o: %.c
	gcc -c $< -o $@ $(FLAGS)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

f: all clean
	./fillit ex_fillit
