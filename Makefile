NAME=lib_dll.a
OBJ= convert.o display.o set.o
CPPFLAGS=-g3 -Wall -Wextra -Werror 

all : $(NAME)

$(NAME) : $(OBJ) 
	ar rcs lib_dll.a $(OBJ)
clean:
	rm -f *.o

fclean: clean
	rm -f *.a
re : fclean all

#############
## PATERNS ##
#############
#$@: Nom de la regle
#$<: Nom de la premiere dépendance
#$^: Nom de la toute les dependances
%.o: %.c
	cc $(CPPFLAGS) -c $< -o $@
.PHONY: all clean fclean re
