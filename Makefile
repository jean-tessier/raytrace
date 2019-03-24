CC=g++

test: tests/tests.cpp tests/vector.unit.cpp vector/vector.o
	$(CC) -o test tests/tests.cpp vector/vector.o

vector/vector.o: vector/vector.cpp
	$(CC) -c vector/vector.cpp -o vector/vector.o