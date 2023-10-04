OBJS = main.o tokenizer.o history.o
CFLAGS=-g -o3

all: main

main: $(OBJS)
	cc -o main $(CFLAGS) $(OBJS)

$(OBJS): tokenizer.h history.h

clean: rm -f *.o main

run: main
	./main
