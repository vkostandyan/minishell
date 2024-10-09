NAME = minishell

CFLAGS = -Wall -Wextra -Werror #-lreadline #-fsanitize=address

CC = cc 

SRCS =	main.c

HEADER =	libft.h \
			helpers.h \
			minishell.h \
			tokenization.h

VALIDATION = 

HELPERS =	merge.c \
			helpers.c \
			ft_arrdup.c \
			clean_data.c \
			array_utils.c \
			init_export.c \
			initialization.c 

EXECUTION =	processes.c

TOKENIZATION =	tokenization.c

BUILIN =	cd.c \
			env.c \
			pwd.c \
			echo.c \
			unset.c \
			export.c \
			cd_helpers.c \
			builtin_helpers.c

LIBFT = ft_lstadd_back.c \
		ft_atoi.c \
		ft_itoa.c \
		ft_strcmp.c \
		ft_lstnew.c \
		ft_strdup.c \
		ft_strlen.c \
		ft_strjoin.c \
		ft_strncmp.c \
		ft_isalpha.c \
		ft_isdigit.c \
		ft_isalnum.c \
		ft_putstr_fd.c \
		ft_putchar_fd.c \
		ft_putendl_fd.c

SRCS_DIR = ./sources/
HEADER_DIR = ./headers/
LIBFT_DIR = ./sources/libft/
BUILIN_DIR = ./sources/builtin/
HELPERS_DIR = ./sources/helpers/
EXECUTION_DIR = ./sources/execution/
VALIDATION_DIR = ./sources/validation/
TOKENIZATION_DIR = ./sources/tokenization/

SRCS := $(addprefix $(SRCS_DIR), $(SRCS))
LIBFT := $(addprefix $(LIBFT_DIR), $(LIBFT))
HEADER := $(addprefix $(HEADER_DIR), $(HEADER)) 
BUILIN := $(addprefix $(BUILIN_DIR), $(BUILIN))
HELPERS := $(addprefix $(HELPERS_DIR), $(HELPERS))
EXECUTION := $(addprefix $(EXECUTION_DIR), $(EXECUTION))
VALIDATION := $(addprefix $(VALIDATION_DIR), $(VALIDATION))
TOKENIZATION := $(addprefix $(TOKENIZATION_DIR), $(TOKENIZATION))

SRCS += $(LIBFT)
SRCS += $(BUILIN)
SRCS += $(HELPERS)
SRCS += $(EXECUTION)
SRCS += $(VALIDATION)
SRCS += $(TOKENIZATION)

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

