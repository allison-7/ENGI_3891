CC= g++ -std=c++11
CFLAGS= -g -Wall 
test: Expression.o test.o
	$(CC) $(FLAGS) -o test Expression.o test.o
Expression.o: Expression.cpp Expression.h
	$(CC) $(FLAGS) -c Expression.cpp
test.o: test.cpp
	$(CC) $(FLAGS) -c test.cpp
