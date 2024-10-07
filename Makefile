NAME = minishell
CFLAGS = -Wall -Wextra -Werror #-lreadline #-fsanitize=address
CC = cc 
SRCS =	main.c

HEADER =	minishell.h \
			tokenization.h \
			helpers.h \
			libft.h

VALIDATION = 

HELPERS =	ft_arrdup.c \
			array_utils.c \
			init_export.c \
			initialization.c \
			clean_data.c \
			helpers.c \
			merge.c

EXECUTION =	processes.c

TOKENIZATION =	tokenization.c

BUILIN =	env.c \
			export.c \
			pwd.c \
			echo.c \
			unset.c \
			builtin_helpers.c

LIBFT = ft_lstadd_back.c \
		ft_strcmp.c \
		ft_lstnew.c \
		ft_strdup.c \
		ft_strlen.c \
		ft_strjoin.c \
		ft_strncmp.c \
		ft_putstr_fd.c \
		ft_atoi.c \
		ft_itoa.c \
		ft_isalpha.c \
		ft_isdigit.c \
		ft_isalnum.c

SRCS_DIR = ./sources/
HEADER_DIR = ./headers/
LIBFT_DIR = ./sources/libft/
VALIDATION_DIR = ./sources/validation/
TOKENIZATION_DIR = ./sources/tokenization/
HELPERS_DIR = ./sources/helpers/
BUILIN_DIR = ./sources/builtin/
EXECUTION_DIR = ./sources/execution/

SRCS := $(addprefix $(SRCS_DIR), $(SRCS))
HEADER := $(addprefix $(HEADER_DIR), $(HEADER)) 
LIBFT := $(addprefix $(LIBFT_DIR), $(LIBFT))
VALIDATION := $(addprefix $(VALIDATION_DIR), $(VALIDATION))
TOKENIZATION := $(addprefix $(TOKENIZATION_DIR), $(TOKENIZATION))
HELPERS := $(addprefix $(HELPERS_DIR), $(HELPERS))
BUILIN := $(addprefix $(BUILIN_DIR), $(BUILIN))
EXECUTION := $(addprefix $(EXECUTION_DIR), $(EXECUTION))

SRCS += $(LIBFT)
SRCS += $(VALIDATION)
SRCS += $(TOKENIZATION)
SRCS += $(HELPERS)
SRCS += $(BUILIN)
SRCS += $(EXECUTION)

OBJS = ${SRCS:.c=.o} #> ./sources/validation/a

all: ${NAME}

${NAME}: ${OBJS} Makefile 
	@${CC} ${CFLAGS} -I$(HEADER_DIR) ${OBJS} -o ${NAME} -lreadline

.c.o:
	$(CC) $(CFLAGS) -I$(HEADER_DIR) -c $< -o $(<:.c=.o)

clean:
	rm -rf ${OBJS}

fclean: clean
	rm -rf ${NAME}

re: fclean ${NAME}

.PHONY: all clean fclean re

