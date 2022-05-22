SRCS	= $(wildcard *.c)

OBJS	= $(SRCS:.c=.o)

RM		= rm -f

CC		= cc

NAME	= fract

LIBS	= -lmlx -framework OpenGL -framework AppKit -lm

CFLAGS	= -O3 -I. -Wall -Wextra -Werror

.c.o:
			$(CC) $(CFLAGS) -c $< -o $@

all:			$(NAME)

$(NAME):		$(OBJS)
				gcc ${CFLAGS} -o ${NAME} ${OBJS} ${LIBS}

clean:
			$(RM) $(OBJS) 

fclean:			clean
			$(RM) $(NAME)
			
re:			fclean all

bonus:		$(OBJS) 
			ar rcs $(NAME) $(OBJS) 

.PHONY:		all clean re fclean