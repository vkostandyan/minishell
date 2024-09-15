NAME = minishell
CFLAGS = -Wall -Wextra -Werror -lreadline #-fsanitize=address
CC = cc 
SRCS =	main.c

HEADER = 	

VALIDATION = 

HELPERS =	

TOKENIZATION =	

LIBFT = 

SRCS_DIR = ./sources/
HEADER_DIR = ./headers/
LIBFT_DIR = ./sources/libft/
VALIDATION_DIR = ./sources/validation/

SRCS := $(addprefix $(SRCS_DIR), $(SRCS))
HEADER := $(addprefix $(HEADER_DIR), $(HEADER)) 
LIBFT := $(addprefix $(LIBFT_DIR), $(LIBFT))
VALIDATION := $(addprefix $(VALIDATION_DIR), $(VALIDATION))

SRCS += $(LIBFT)
SRCS += $(VALIDATION)

OBJS = ${SRCS:.c=.o}

all: ${NAME}

${NAME}: ${OBJS} Makefile 
	@${CC} ${CFLAGS} -I$(HEADER_DIR) ${OBJS} -o ${NAME}

.c.o:
	$(CC) $(CFLAGS) -I$(HEADER_DIR) -c $< -o $(<:.c=.o)

clean:
	rm -rf ${OBJS}

fclean: clean
	rm -rf ${NAME}

re: fclean ${NAME}

.PHONY: all clean fclean re

