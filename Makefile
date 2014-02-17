CC = gcc
CFLAGS = -o pqueue
LDFLAGS = -lm

OBJS = queuemain.o queue.o

a.out: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS)

clean: 
	rm $(OBJS) pqueue
