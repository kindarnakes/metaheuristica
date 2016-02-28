OS := $(shell uname)

ifeq ($(OS),Darwin)
   CC = clang++
   FLAGS = -Wall -std=c++14
else ifeq ($(OS),Linux)
   CC = g++
   FLAGS = -Wall -lgsl -lgslcblas -std=c++11
endif

DEBUG = -g
OPTIMIZE = -O3

all:
	$(CC) -o main main.cpp $(FLAGS)

optimize:
	$(CC) -o main main.cpp $(FLAGS) $(OPTIMIZE)

debug:
	$(CC) -o testInstance testInstance.cpp $(FLAGS) $(DEBUG)

test:
	$(CC) -o testInstance testInstance.cpp $(FLAGS)

clean:
	rm main