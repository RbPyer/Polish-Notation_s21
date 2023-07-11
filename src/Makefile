CC = gcc
CFLAGS = -Wall -Wextra -Wextra -fsanitize=leak -lm


OBJ_DIR = ../build/
RM_ALL = rm -rf *.o *.a *.so ../build/*

C_LANG = clang-format -i *.c *.h
MAKE = make

ADD = git add .
COMMIT = git commit -m "new task"
PUSH = git push origin develop

all: 
	$(CC) $(CFLAGS) calculate.c draw.c stack.c parse.c graph.c -o $(OBJ_DIR)graph


build_with_render:
	$(CC) $(CFLAGS) -DrenderString calculate.c draw.c stack.c parse.c graph.c -o $(OBJ_DIR)graph

rebuild:
	$(MAKE) clean
	$(MAKE) all


clang:
	$(C_LANG)

clean:
	$(RM_ALL)


git:
	$(RM_ALL)
	$(C_LANG)
	$(ADD)
	$(COMMIT)
	$(PUSH)
