CC = gcc
EXEC = j-shell
OBJS = j-shell.o error.o

$(EXEC): $(OBJS)
		$(CC) -o $(EXEC) $(OBJS)
myShell.o:j-shell.c include/j-shell.h
		$(CC) -c $<
error.o:error.c include/j-shell.h
		$(CC) -c $<
clean:
		rm -rf $(EXEC) *.o
