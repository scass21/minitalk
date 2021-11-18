SRCS_CLIENT		=	client.c
NAME_CLIENT		=	client
SRCS_SERV		=	server.c 		
NAME_SERV		=	server
OBJ_SERV		=	$(SRCS_SERV:c=o)
OBJ_CLIENT		=	$(SRCS_CLIENT:c=o)
LIBFTDIR 		=	libft
LIBFT 			=	$(LIBFTDIR)/libft.a
HEADER			=	minitalk.h
RM				=	rm -f
CC				=	gcc
CFLAGS			=	-Wall -Wextra -Werror -I.

%.o:			%.c $(HEADER)
				$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) 

all:			$(NAME_CLIENT) $(NAME_SERV)
				@echo "minitalk is ready"

bonus:			$(NAME_CLIENT) $(NAME_SERV)
				@echo "minitalk is ready"

$(LIBFT):		libft/*.c libft/*.h
				$(MAKE) -C $(LIBFTDIR)

$(NAME_CLIENT):	$(LIBFT) $(OBJ_CLIENT) $(HEADER)
				$(CC) $(CFLAGS) $(OBJ_CLIENT) -o $(NAME_CLIENT) $(LIBFT)

$(NAME_SERV):	$(LIBFT) $(OBJ_SERV) $(HEADER)
				$(CC) $(CFLAGS) $(OBJ_SERV) -o $(NAME_SERV) $(LIBFT)

clean:
				$(MAKE) -C $(LIBFTDIR) clean
				$(RM) $(OBJ_CLIENT)
				$(RM) $(OBJ_SERV)

fclean:			clean
				$(MAKE) -C $(LIBFTDIR) fclean
				$(RM) $(NAME_CLIENT)
				$(RM) $(NAME_SERV)

re:				fclean all
norm:
				norminette *.c minitalk.h libft/*.c libft/libft.h

.PHONY:			all clean fclean re