SERVER=server
CLIENT=client

EXECS = $(SERVER) $(CLIENT)

SERV_SRC=server.c
CLI_SRC=client.c
SRCDIR = .
OBJDIR = obj
SERV_OBJ = $(OBJDIR)/server.o
CLI_OBJ = $(OBJDIR)/client.o
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
MK = mkdir -p

.DEFAULT_GOAL=all

$(OBJDIR)/%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR): $(SRCDIR)
	$(MK) $@

all: $(OBJDIR) $(EXECS)

$(SERVER): $(SERV_OBJ)
	$(CC) $(CFLAGS) -o $@ $(SERV_OBJ)

$(CLIENT): $(CLI_OBJ)
	$(CC) $(CFLAGS) -o $@ $(CLI_OBJ)

clean:
	$(RM) $(OBJDIR)

fclean: clean
	$(RM) $(EXECS)

re:	fclean all

.PHONY: all clean fclean re