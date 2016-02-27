OS := $(shell uname)
ifeq ($(OS),Darwin)
   CC = clang++
   FLAGS = -Wall -std=c++14
   OPTIMIZE = -O3
else ifeq ($(OS),Linux)
   CC = g++
   FLAGS = -Wall -lgsl -lgslcblas -std=c++14
   OPTIMIZE = -O3
endif

all:
	$(CC) -o main main.cpp $(FLAGS)

optimize:
	$(CC) -o main main.cpp $(FLAGS) $(OPTIMIZE)

test:
	$(CC) -o testInstance testInstance.cpp $(FLAGS)

clean:
	rm main