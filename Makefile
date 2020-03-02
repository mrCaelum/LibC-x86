##
## EPITECH PROJECT, 2020
## ASM_minilibc_2019
## File description:
## Makefile
##

SRC_DIR	=	./src/
TESTS_DIR	=	./tests/

NAME	=	libasm.so
TESTS_NAME	=	tests_$(NAME)

SRCS	=	$(wildcard $(SRC_DIR)*.asm)
OBJS	=	$(SRCS:$(SRC_DIR)%.asm=$(SRC_DIR)%.o)
TESTS_SRCS  =   $(wildcard $(TESTS_DIR)*.c)
TESTS_OBJS	=	$(TESTS_SRCS:$(TESTS_DIR)%.c=$(TESTS_DIR)%.o)

LDFLAGS	+=	-L./ -lasm -ldl -lcriterion --coverage
CFLAGS	+=	-fprofile-arcs -ftest-coverage -fno-builtin

%.o: %.asm
	nasm -f elf64 $< -o $@

%.o: %.c
	$(CC) -c $< -o $@ $(LDFLAGS) $(CFLAGS)

all: $(NAME)

$(NAME): $(OBJS)
	ld -shared -o $(NAME) $(OBJS)

tests_run: all $(TESTS_OBJS)
	$(CC) -o $(TESTS_NAME) $(TESTS_OBJS) $(LDFLAGS) $(CFLAGS)
	./$(TESTS_NAME)

clean:
	rm -f $(OBJS)
	rm -f $(TESTS_OBJS)
	rm -f $(TESTS_DIR)*.gcda
	rm -f $(TESTS_DIR)*.gcno

fclean: clean
	rm -f $(NAME)
	rm -f $(TESTS_NAME)

re:	fclean all

.PHONY: all tests_run clean fclean re