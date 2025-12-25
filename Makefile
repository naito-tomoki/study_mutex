NAME				=	mutex

CC					=	cc
CFLAGS				=	-Wall -Wextra -Werror

LIBS				=	-lpthread

override DIR_SRC	=	src
override DIR_INC	=	include
override DIR_OBJ	=	build

SRC_DIR_LIST		=	$(shell find $(DIR_SRC))
INC_DIR_LIST		=	$(shell find $(DIR_INC))

SRCS				=	$(foreach srcdir,$(SRC_DIR_LIST),$(wildcard $(srcdir)/*.c))
INCS				=	$(foreach incdir,$(INC_DIR_LIST),$(wildcard $(incdir)/*.h))
OBJS				=	$(SRCS:$(DIR_SRC)/%.c=$(DIR_OBJ)/%.o)

.DEFAULT_GOAL		=	all

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@ $(LIBS)

$(DIR_OBJ)/%.o: $(DIR_SRC)/%.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

clean:
	rm -rf $(DIR_OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
