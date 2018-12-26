CC = g++
LINKERFLAG = -lSDL2
COMPILERFLAGS = -Wall
OBJS = 	main.cpp \
		sprite.cpp \
		mainwindow.cpp \
		game.cpp \
		ship.cpp \
		bullet.cpp \
		asteroid.cpp \
		inputcontrol.cpp

NAME = asteroids

all: $(OBJS)
	$(CC) $(COMPILERFLAGS) $(OBJS) $(LINKERFLAG) -o $(NAME)