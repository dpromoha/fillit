NAME	=	fillit

FLAGS	=	-Wall -Werror -Wextra -I./headers

SRCDIR	=	./sources/

OBJDIR	=	./objects/

LIBDIR	=	./libft/

SRC		=	additional_func.c fillit.c write_in.c tetrx.c validation.c help_to_build.c 

OBJ		=	$(addprefix $(OBJDIR), $(SRC:.c=.o))

LIB		=	libft.a

all: $(NAME)

$(NAME): $(OBJDIR) $(OBJ) $(LIBDIR)$(LIB)
	gcc -o $(NAME) $(OBJ) $(LIBDIR)$(LIB) $(FLAGS)

$(OBJ): $(OBJDIR)%.o : $(SRCDIR)%.c
	gcc -o $@ -c $< $(FLAGS)

$(LIBDIR)$(LIB):
	make -C $(LIBDIR)

$(OBJDIR):
	mkdir $(OBJDIR) 

clean:
	make -C $(LIBDIR) clean
	rm -rf $(OBJ) $(OBJDIR)

fclean: clean
	make -C $(LIBDIR) fclean
	rm -rf $(NAME)

re: fclean $(NAME)

norm:
	norminette -R CheckForbiddenSourceHeader

comp:
	@gcc -g $(FLAGS) $(addprefix $(SRCDIR), $(SRC)) libft-gnl/libft.a -I.headers/fillit.h -o debug
