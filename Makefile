NAME = libftprintf.a

SOURCES = 	ft_printf.c		\
			ft_putnbr_ptr.c

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
	make clean -s -C ./Libft/
	
	
clean : 
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re

