
CC = g++
CFLAGS = -g

%.o : %.cpp
	$(CC) -c $(CFLAGS) $< -o $@

objects = \
	main/main.o \
	mvc/Url.o \
	mvc/Dispatcher.o \
	services/StudentsService.o \
	controllers/BaseController.o \
	controllers/StudentsController.o

executable = \
	students

compile: $(objects)

link:
	g++ $(objects) -o $(executable)	

all: compile link

clean: 
	rm -f $(objects) $(executable)


