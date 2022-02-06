FLAGS = -Werror -Wall -Wextra

NAME  = fdf

SRC   = ft_split.c\
		ft_strlen.c\
		get_list.c\
		main.c\
		pixel_lst.c\
		utils.c\
		hooks.c\
		initializer.c\
		drawer.c

OBJ = $(SRC:.c=.o)

LIBXL = -lmlx -lXext -lX11 

all : $(NAME)

$(NAME) : $(OBJ)
	@echo "Creating LINUX executable $(NAME) ..."
	@gcc -o $(NAME) $(OBJ) $(LIBXL)

%.o: %.c 
	@gcc $(CFLAGS) -c $<

clean :
	@echo "Removing object files ..."
	@rm -f $(OBJ)

fclean : clean
	@echo "Removing $(NAME) ..."
	@rm -f $(NAME)

re : fclean all

.PHONY : clean fclean re 