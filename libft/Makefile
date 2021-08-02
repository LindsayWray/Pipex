# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: lwray <lwray@student.codam.nl>               +#+                      #
#                                                    +#+                       #
#    Created: 2021/02/25 13:29:50 by lwray         #+#    #+#                  #
#    Updated: 2021/02/25 13:31:24 by lwray         ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME := libft.a
HEADERFILES := libft.h ft_printf/ft_printf.h get_next_line/get_next_line.h
SRCS := ft_atoi.c \
	ft_isdigit.c \
	ft_memcpy.c \
	ft_putstr_fd.c \
	ft_strlcpy.c \
	ft_strtrim.c \
	ft_bzero.c \
	ft_isprint.c \
	ft_memmove.c \
	ft_split.c \
	ft_splits.c \
	ft_strlen.c \
	ft_substr.c \
	ft_calloc.c \
	ft_itoa.c \
	ft_memset.c \
	ft_strchr.c \
	ft_strmapi.c \
	ft_tolower.c \
	ft_isalnum.c \
	ft_memccpy.c \
	ft_putchar_fd.c \
	ft_strdup.c \
	ft_strncmp.c \
	ft_strequal.c \
	ft_toupper.c \
	ft_isalpha.c \
	ft_memchr.c \
	ft_putendl_fd.c \
	ft_strjoin.c \
	ft_strnstr.c \
	ft_isascii.c \
	ft_memcmp.c \
	ft_putnbr_fd.c \
	ft_strlcat.c \
	ft_strrchr.c \
	ft_lstadd_back.c \
	ft_lstadd_front.c \
	ft_lstclear.c \
	ft_lstdelone.c\
	ft_lstiter.c \
	ft_lstlast.c \
	ft_lstmap.c \
	ft_lstnew.c \
	ft_lstsize.c \
	ft_printf/flags_s.c \
	ft_printf/filler.c \
	ft_printf/flags_u.c \
	ft_printf/ft_putnstr.c \
	ft_printf/flagcheck.c \
	ft_printf/flags_x.c \
	ft_printf/ft_putptr.c \
	ft_printf/flags_c.c \
	ft_printf/ft_conversion.c \
	ft_printf/ft_printf.c	\
	ft_printf/is_specifier.c \
	ft_printf/flags_d.c \
	ft_printf/ft_putchar.c \
	ft_printf/flags_p.c \
	ft_printf/ft_putnbr.c \
	ft_printf/char_count.c \
	ft_printf/num_len.c \
	ft_printf/ft_strlen.c \
	ft_printf/flags_null.c \
	ft_printf/flags_f.c \
	ft_printf/ft_putdecimal.c \
	get_next_line/get_next_line.c \
	get_next_line/get_next_line_utils.c

FLAGS := -Wall -Wextra -Werror
OBJS := ${SRCS:%.c=obj/%.o}

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

obj/%.o: %.c $(HEADERFILES)
	@mkdir -p $(dir $@)
	gcc $(FLAGS) -c $< -o $@

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean all

norm:
	norminette $(SRCS) $(HEADERFILES)

.PHONY: all clean fclean re
