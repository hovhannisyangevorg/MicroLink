NAME			:=	server client
INC_DIR			:=	include
SRC_DIR			:=	src
OBJ_DIR			:=	obj
OBJ_SERV_DIR	:=	obj/server
OBJ_CLI_DIR 	:=	obj/client


HDRS		:=	$(wildcard $(INC_DIR)/*.h)
SRCS		:=	$(wildcard $(SRC_DIR)/*.c)
SERV_SRCS	:= 	$(filter-out $(SRC_DIR)/client.c, $(SRCS))
CLI_SRCS	:= 	$(filter-out $(SRC_DIR)/server.c, $(SRCS))
SERV_OBJS	:=	$(patsubst $(SRC_DIR)/%.c, $(OBJ_SERV_DIR)/%.o, $(SERV_SRCS))
CLI_OBJS	:=	$(patsubst $(SRC_DIR)/%.c, $(OBJ_CLI_DIR)/%.o, $(CLI_SRCS))

# tools
CC 		:= cc
CFLAGS 	:= -Wall -Wextra -Werror
INCS 	:= -I$(INC_DIR)
RM 		:= rm -rf
MK		:= mkdir -p

.DEFAULT_GOAL:=all

$(OBJ_SERV_DIR)/%.o: $(SRC_DIR)/%.c $(HDRS)
	$(CC) $(CFLAGS) $(INCS) -c $< -o $@

$(OBJ_CLI_DIR)/%.o: $(SRC_DIR)/%.c $(HDRS)
	$(CC) $(CFLAGS) $(INCS) -c $< -o $@

$(OBJ_SERV_DIR): $(SRC_DIR)
	$(MK) $@

$(OBJ_CLI_DIR): $(SRC_DIR)
	$(MK) $@

all: $(NAME)

server:	$(OBJ_SERV_DIR) $(SERV_OBJS)
	$(CC) $(CFLAGS) $(INCS) -o $@ $(SERV_OBJS)

client:	$(OBJ_CLI_DIR) $(CLI_OBJS)
	$(CC) $(CFLAGS) $(INCS) -o $@ $(CLI_OBJS)

clean:
	$(RM) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re