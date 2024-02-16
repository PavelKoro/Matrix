CC = g++
CFLAGS = -Wall -Wextra

all: build

build: Matrix2D.cpp Gauss.cpp Equation.cpp main.cpp
	$(CC) $(CFLAGS) Matrix2D.cpp Gauss.cpp Equation.cpp main.cpp -o main