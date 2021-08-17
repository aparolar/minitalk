C_NAME		=	client

S_NAME		=	server

SERVER		=	src/server/

CLIENT		=	src/client/

O			=	obj/

I			=	inc/

LIBFTP		=	lib/libft/

SSRCS		=	$(SERVER)main.c

CSRCS		=	$(CLIENT)main.c

SOBJS		=	$(SSRCS:$SERVER%.c=$O%.o)

COBJS		=	$(CSRCS:$CLIENT%.c=$O%.o)

LIBFT		=	-L lib/libft/ -lft

CC			=	gcc -g3 -fsanitize=address #-O3 #clang

FLAGS		=	-Wall -Wextra -Werror

all:			$(C_NAME) $(S_NAME)

$(C_NAME):		$(COBJS)
				make -C $(LIBFTP)
				printf "Making Client\n\n"
				$(CC) $(FLAGS) $(CSRCS) $(LIBFT) -o $(C_NAME)

$(S_NAME):		$(SOBJS)
				make -C $(LIBFTP)
				printf "Making Server\n\n"
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
