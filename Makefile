# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: lwray <lwray@student.codam.nl>               +#+                      #
#                                                    +#+                       #
#    Created: 2021/07/26 08:01:17 by lwray         #+#    #+#                  #
#    Updated: 2021/07/26 14:44:32 by lwray         ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME := pipex
BONUS := bonus
HEADERFILES := srcs/pipex.h
PIPEX_SRCS := 	srcs/main.c
BONUS_SRCS := 	srcs/pipex_bonus.c \
				srcs/heredoc_bonus.c
SHARED_SRCS := 	srcs/split_command.c \
				srcs/command_trim.c \
				srcs/error_handler.c \
				srcs/get_path.c \
				srcs/process.c

FLAGS := -Wall -Wextra -Werror
OBJFILES := $(PIPEX_SRCS:srcs/%.c=obj/%.o) $(SHARED_SRCS:srcs/%.c=obj/%.o)
BONUS_OBJFILES := $(BONUS_SRCS:srcs/%.c=obj/%.o) $(SHARED_SRCS:srcs/%.c=obj/%.o)
LIBFT := libft/

all: $(NAME)

$(NAME): $(OBJFILES) 
	@make -C $(LIBFT)
	gcc -o $@ $^ -L $(LIBFT) -lft

$(BONUS): $(BONUS_OBJFILES)
	@make -C $(LIBFT)
	gcc -o pipex $^ -L $(LIBFT) -lft

obj/%.o: srcs/%.c $(HEADERFILES)
	@mkdir -p $(dir $@)
	gcc -c $(FLAGS) -o $@ $<

clean:
	rm -f $(OBJFILES) $(BONUS_OBJFILES)
	@make fclean -C $(LIBFT)

fclean: clean
	rm -f $(NAME)

re: fclean all

norm:
	norminette $(PIPEX_SRCS) $(BONUS_SRCS) $(SHARED_SRCS) $(HEADERFILES)
	make norm -C $(LIBFT)

.PHONY: all clean fclean re norm bonus
