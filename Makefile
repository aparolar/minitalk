C_NAME		=	mtclient

S_NAME		=	mtserver

SERVER		=	src/server

CLIENT		=	src/client

O			=	obj/

I			=	inc/

LIBFTP		=	lib/libft/

SSRCS		=	

CSRCS		=	

SOBJS		=	$(SSRCS:$SERVER%.c=$O%.o)

COBJS		=	$(CSRCS:$CLIENT%.c=$O%.o)

LIBFT		=	-L libft

CC			=	gcc -g3 -fsanitize=address #-O3 #clang

FLAGS		=	-Wall -Wextra -Werror

all:			$(C_NAME) $(S_NAME)

$(C_NAME):		$(COBJS)
				make -C $(LIBFTP)
				printf "Making Client\n"
				$(CC) $(FLAGS) $(CSRCS) $(LIBFT) -o $(C_NAME)

$(S_NAME):		$(SOBJS)
				make -C $(LIBFTP)
				printf "Making Slient\n"
				$(CC) $(FLAGS) $(SSRCS) $(LIBFT) -o $(S_NAME)

#$O%.o:			$(COBJS)
#				$(CC) $(FLAGS) -c $< -o $@

re:				fclean
				make re -C $(LIBFTP)
				$(MAKE)

clean:
				rm -rf $O*.o

fclean:			clean		
				rm -rf $(C_NAME)
				rm -rf $(S_NAME)

#test:			re
#				./fract_ol 1

#dbg_test:		re

.PHONY:			all re clean fclean
