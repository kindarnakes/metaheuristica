OS := $(shell uname)

ifeq ($(OS),Darwin)
   CC = clang++
   FLAGS = -Wall -I/usr/local/include/  -L /usr/local/lib/ -lgsl -lgslcblas -lm -std=c++14
else ifeq ($(OS),Linux)
   CC = g++
   FLAGS = -Wall -lgsl -lgslcblas -lm -std=c++14
endif

DEBUG = -g

all:
	$(CC) -o main main.cpp $(FLAGS)

debug:
	$(CC) -o main main.cpp $(FLAGS) $(DEBUG)

clean:
	rm main
