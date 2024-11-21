
CC = g++ --std=c++23
CFLAGS = -g

%.o : %.cpp
	$(CC) -c $(CFLAGS) $< -o $@

objects = \
	main/main.o \
	common/Logger.o \
	mvc/Url.o \
	mvc/Dispatcher.o \
	mvc/ObjectMapper.o \
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


