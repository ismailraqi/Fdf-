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
		drawing.c\
		lines_lst.c

OBJ = $(SRC:.c=.o)

LIBL = -lmlx -lXext -lX11 
LIBM = -lmlx -lm -framework OpenGL -framework AppKit

all : $(NAME)

$(NAME) : $(OBJ)
	@echo "Creating LINUX executable $(NAME) ..."
	@gcc -o $(NAME) $(OBJ) $(LIBL)

%.o: %.c 
	@gcc $(CFLAGS) -c $<

mac	: $(OBJ)
	gcc -o $(NAME) $(OBJ) $(LIBM)

clean :
	@echo "Removing object files ..."
	@rm -f $(OBJ)

fclean : clean
	@echo "Removing $(NAME) ..."
	@rm -f $(NAME)

re : fclean all

.PHONY : clean fclean re mac