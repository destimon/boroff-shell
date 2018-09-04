# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dcherend <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/17 15:19:05 by dcherend          #+#    #+#              #
#    Updated: 2018/09/04 18:11:04 by dcherend         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 			= 21sh

LIBFT 			= $(LIBFT_DIR)libft.a
LIBFT_DIR 		= $(LIB_DIR)libft/
LIBFT_FLAGS 	= -lft -L $(LIBFT_DIR)
LIBFT_DIR 		= ./lib/libft/
LIBFT_HDR_DIR 	= ./lib/libft/
OBJ_DIR 		= ./obj/
SRC_DIR 		= ./src/

CC 				= gcc
CFLAGS 			= -I$(HDR_DIR) -I$(LIBFT_HDR_DIR) # -Wall -Werror -Wextra \

ETC_DIR         = etc/
INTERFACE_DIR   = interface/
CORE_DIR        = core/
CMD_DIR         = cmd/
INPUT_DIR       = input/

SRC 			= main.c $(ETC_DIR)environ.c $(INTERFACE_DIR)term.c $(INTERFACE_DIR)ui.c \
                $(ETC_DIR)utils.c $(ETC_DIR)signals.c $(CORE_DIR)core.c $(CMD_DIR)cmd.c $(CMD_DIR)cmd_cd.c \
                $(INPUT_DIR)input.c $(INPUT_DIR)input2.c $(CORE_DIR)execute.c $(ETC_DIR)utils2.c \
                $(ETC_DIR)error.c $(CMD_DIR)cmd_env.c $(ETC_DIR)envmanage.c $(ETC_DIR)history.c \
                $(INPUT_DIR)qu_deleter.c $(ETC_DIR)quotes.c $(INPUT_DIR)combinations.c \
                $(CORE_DIR)btree.c $(INPUT_DIR)moving.c
OBJ 			= $(addprefix $(OBJ_DIR), $(SRC:.c=.o))

LIB_BIN 		= $(LIBFT_DIR)libft.a
LIB_FLAGS 		= -lft -L$(LIBFT_DIR)
LIB 			= $(MAKE) -C $(LIBFT_DIR)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(OBJ) $(LIBFT_FLAGS) -o $(NAME) -ltermcap

$(OBJ): | $(OBJ_DIR)

$(OBJ_DIR):
	mkdir $(OBJ_DIR) $(OBJ_DIR)$(ETC_DIR) $(OBJ_DIR)$(INTERFACE_DIR) $(OBJ_DIR)$(CORE_DIR) \
	$(OBJ_DIR)$(CMD_DIR) $(OBJ_DIR)$(INPUT_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c inc/$(HEAD)
	$(CC) -c $< -o $@ $(HEADERS_FLAGS) $(CFLAGS)

$(LIBFT):
	make -C $(LIBFT_DIR)

clean:
	rm -f $(OBJ)
	make clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME)
	rm -rf $(OBJ_DIR)
	make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re
