CC= gcc
CFLAGS= -O2 -Wall -Wextra -Werror -ggdb -O0 -ansi -std=c11
CLIBS= -lm
EXE= executable
OBJ= obj/
SRC= src/
INCL= include/

FILEC:= $(wildcard $(SRC)*.c)
FILEH:= $(wildcard $(INCL)*.h)
FILEO:= $(patsubst $(SRC)%.c,$(OBJ)%.o,$(FILEC))

$(EXE) : $(FILEO)
	$(CC) $(CFLAGS) -o $@ $^ $(CLIBS)

$(OBJ)main.o : $(SRC)main.c $(FILEH)
	$(CC) $(CFLAGS) -o $@ -c $<

$(OBJ)%.o : $(SRC)%.c $(INCL)%.h
	$(CC) $(CFLAGS) -o $@ -c $<

$(OBJ)insert.o : $(SRC)insert.c
	$(CC) $(CFLAGS) -o $@ -c $<

$(OBJ)select.o : $(SRC)select.c
	$(CC) $(CFLAGS) -o $@ -c $<

clean :
	rm -rf $(OBJ)*.o
	rm -rf $(EXE)
