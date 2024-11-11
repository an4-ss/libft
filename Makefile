CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCM = ft_strlcpy.c ft_toupper.c ft_atoi.c ft_memchr.c ft_strlen.c ft_isascii.c ft_bzero.c \
		ft_memcmp.c ft_split.c ft_strncmp.c ft_calloc.c ft_memcpy.c ft_strchr.c ft_strnstr.c \
		ft_putnbr_fd.c ft_strmapi.c ft_striteri.c ft_isalnum.c ft_memmove.c ft_strdup.c \
		ft_strrchr.c ft_isalpha.c ft_memset.c ft_strtrim.c ft_isdigit.c ft_strjoin.c \
		ft_substr.c ft_isprint.c ft_strlcat.c ft_tolower.c ft_itoa.c ft_putchar_fd.c \
		ft_putstr_fd.c ft_putendl_fd.c \

OBJM = $(SRCM:.c=.o)
NAME = libft.a

all: $(NAME)

$(NAME): $(OBJM) libft.h
	ar -rc $(NAME) $(OBJM)

clean:
	rm -f $(OBJM)

fclean: clean
	rm -f $(NAME)

re: fclean all

walid: clean
	@echo 'hello walid'

.PHONY: 