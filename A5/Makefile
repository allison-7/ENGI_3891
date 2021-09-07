CC= g++ -std=c++11
CFLAGS = -g -wall
test: Pumpkin.o Carriage.o test.o
	$(CC) $(FLAGS) -o test Pumpkin.o Carriage.o test.o
Pumpkin.o: Pumpkin.cpp Pumpkin.h
	$(CC) $(FLAGS) -c Pumpkin.cpp
Carriage.o: Carriage.cpp Carriage.h date.h Pumpkin.h
	$(CC) $(FLAGS) -c Carriage.cpp
test.o: test.cpp
	$(CC) $(FLAGS) -c test.cpp
