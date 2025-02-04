NAME	= mysh

CC	= gcc

RM	= rm -f

SRCS	= lib/my_putstr.c \
			lib/my_putchar.c \
			lib/my_put_nbr.c \
			lib/my_strcat.c \
			lib/my_strcmp.c \
			lib/my_strlen.c \
			lib/my_getnbr.c \
			lib/my_strcpy.c \
			lib/my_strncat.c \
			lib/my_strdup.c \
			lib/my_revstr.c \
			lib/my_strncmp.c \
			lib/my_str_to_word_array.c \
			lib/my_strncpy.c \
			lib/my_strchr.c \
			lib/my_isdigit.c \
			lib/my_isneg.c \
			lib/my_atoi.c \
			lib/my_str_isnum.c \
			lib/my_str_isalpha.c \
			lib/my_str_islower.c \
			lib/my_str_isupper.c \
			lib/my_str_isprintable.c \
			lib/my_put_unsigned_nbr.c \
			lib/printf/argumenth.c \
			lib/printf/fonctionbigx.c \
			lib/printf/fonctionc.c \
			lib/printf/fonctiond.c \
			lib/printf/fonctionf.c \
			lib/printf/fonctionld.c \
			lib/printf/fonctionlld.c \
			lib/printf/fonctionn.c \
			lib/printf/fonctiono.c \
			lib/printf/fonctionp.c \
			lib/printf/fonctions.c \
			lib/printf/fonctionu.c \
			lib/printf/fonctionx.c \
			lib/printf/my_printf.c \
			lib/printf/printpourcent.c \
			src/my_setenv.c \
			src/my_unsetenv.c \
			src/cd.c \
			src/command.c \
			src/prompt.c \
			src/redirection.c \
			main.c \

OBJS	= $(SRCS:.c=.o)

CFLAGS = -I ./utilities/
CFLAGS += -Wall -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	 $(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
