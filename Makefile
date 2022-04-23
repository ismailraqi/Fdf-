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
		lines_lst.c\
		bernstein.c\
		projection.c\
		put_pixel.c\
		rotation.c\
		put_info_into_image.c

OBJ = ft_split.o\
		ft_strlen.o\
		get_list.o\
		main.o\
		pixel_lst.o\
		utils.o\
		hooks.o\
		initializer.o\
		drawing.o\
		lines_lst.o\
		bernstein.o\
		projection.o\
		put_pixel.o\
		rotation.o\
		put_info_into_image.o

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

.PHONY : clean fclean re mac all