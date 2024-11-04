
CC = g++
CFLAGS = -g

all: students
	@find . -type d -depth 1 -exec make -C {} \;	
	find . -name \*.o | xargs g++ -o $< 	

clean: 
	@find . -name \*.o -exec rm -f {} \; -print


