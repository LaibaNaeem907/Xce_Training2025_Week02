CC = gcc
CFLAGS = -Wall -g -MMD -MP
source_files = $(wildcard *.c)       
object_files = $(source_files:.c=.o)  
dep_files = $(object_files:.o=.d)    
final = program

all: $(final)

$(final): $(object_files)
	$(CC) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

debug: CFLAGS += -g
debug: clean $(final)

clean:
	rm -f $(final) *.o *.d
-include $(dep_files)
