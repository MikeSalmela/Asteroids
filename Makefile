CC = g++
LINKERFLAG = -lSDL2

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
	$(CC) $(OBJS) $(LINKERFLAG) -o $(NAME)