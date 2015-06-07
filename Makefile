SRCS=main.cpp src/*

all: main

main: 
		g++ $(SRCS) -o main
