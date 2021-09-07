CXXFLAGS = -g -Wall -std=c++11
test: Pumpkin.o Carriage.o PumpkinPatch.o test.o 
	$(CXX) -o test Pumpkin.o Carriage.o PumpkinPatch.o test.o
Pumpkin.o: Pumpkin.cpp Pumpkin.h
Carriage.o: Carriage.cpp Carriage.h date.h Pumpkin.h
test.o: test.cpp
PumpkinPatch.o: PumpkinPatch.cpp PumpkinPatch.h
