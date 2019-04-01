CC=g++ -std=c++11
SHAPE_FILES=shape/shape.h tuple/tuple.o

test: tests/tests.cpp tests/vector.unit.cpp tests/plane.unit.cpp tests/tuple.unit.cpp vector/vector.o plane/plane.o tuple/tuple.o
	$(CC) -o test tests/tests.cpp vector/vector.o plane/plane.o tuple/tuple.o

vector/vector.o: vector/vector.cpp vector/vector.h tuple/tuple.o
	$(CC) -c vector/vector.cpp -o vector/vector.o

plane/plane.o: plane/plane.cpp plane/plane.h $(SHAPE_FILES)
	$(CC) -c plane/plane.cpp -o plane/plane.o

tuple/tuple.o: tuple/tuple.cpp tuple/tuple.h
	$(CC) -c tuple/tuple.cpp -o tuple/tuple.o