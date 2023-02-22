# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: macastan <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/09 14:27:45 by macastan          #+#    #+#              #
#    Updated: 2023/02/16 10:53:23 by macastan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT = ./libft/libft.a

CLIENT = client
SERVER = server
CLIENT_BONUS = client_bonus
SERVER_BONUS = server_bonus

FILE_C = client.c
OBJS_C = $(FILE_C:%.c=%.o)

FILE_S = server.c
OBJS_S = $(FILE_S:%.c=%.o)

BONUS_C = client_bonus.c
BONUS_OBJS_C = $(BONUS_C:%.c=%.o)

BONUS_S = server_bonus.c
BONUS_OBJS_S = $(BONUS_S:%.c=%.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

all: $(SERVER) $(CLIENT)

$(LIBFT):
	@$(MAKE) -C ./libft

$(CLIENT): $(OBJS_C) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJS_C) $(LIBFT) -o client

$(SERVER): $(OBJS_S) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJS_S) $(LIBFT) -o server

bonus: $(CLIENT_BONUS) $(SERVER_BONUS)

$(CLIENT_BONUS): $(BONUS_OBJS_C) $(LIBFT)
	@$(CC) $(CFLAGS) $(BONUS_OBJS_C) $(LIBFT) -o client_bonus

$(SERVER_BONUS): $(BONUS_OBJS_S) $(LIBFT)
	@$(CC) $(CFLAGS) $(BONUS_OBJS_S) $(LIBFT) -o server_bonus

clean:
	@$(MAKE) clean -C ./libft
	@$(RM) $(OBJS_C) $(OBJS_S)
	@$(RM) $(BONUS_OBJS_C) $(BONUS_OBJS_S)

fclean: clean
	@$(MAKE) fclean -C ./libft
	@$(RM) $(CLIENT) $(SERVER)
	@$(RM) $(CLIENT_BONUS) $(SERVER_BONUS)

re: fclean all
