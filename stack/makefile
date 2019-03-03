OBJ = test.o stack.o
PROG = test
CFLAGS += -Wall -g

all : $(PROG)

test : $(OBJ)
	g++ -o $@ $^ $(CFLAGS)

clean : 
	$(RM) $(OBJ) $(PROG)
