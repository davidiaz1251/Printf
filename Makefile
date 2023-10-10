NAME = libftprintf.a

SOURCES = 	ft_printf.c		\
			ft_putnbrs.c	\
			ft_print.c

OBJECTS = $(SOURCES:.c=.o)

LIBRERY = libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror


all : $(NAME)

$(NAME) : $(OBJECTS) $(LIBRERY)
	$(AR) -crs $(NAME) $(OBJECTS)

$(LIBRERY) : 
	make bonus -s -C ./Libft/
	CP ./Libft/$(LIBRERY) ./$(NAME)
	MV ./Libft/$(LIBRERY) ./
	

clean : 
	rm -f $(OBJECTS)
	make clean -s -C ./Libft/

fclean: clean
	rm -f $(NAME) $(LIBRERY)

re: fclean all

.PHONY: all bonus clean fclean re

