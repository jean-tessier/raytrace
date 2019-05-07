CC=g++ -std=c++17 -g

PROGRAM_FILES=vector/vector.o \
		  plane/plane.o \
		  tuple/tuple.o \
		  camera/camera.o \
		  fileHandler/fileHandler.o \
		  world/world.o \
		  sphere/sphere.o

#HEADERS=vector/vector.h \
		plane/plane.h \
		tuple/tuple.h \
		camera/camera.h \
		fileHandler/fileHandler.h \
		world/world.h

#SOURCE_FILES=vector/vector.cpp \
			 plane/plane.cpp \
			 tuple/tuple.cpp \
			 camera/camera.cpp \
			 fileHandler/fileHandler.cpp \
			 world/world.cpp

SHAPE_FILES=shape/shape.h tuple/tuple.o

TEST_FILES=tests/tests.cpp \
	  	   tests/vector.unit.cpp \
		   tests/plane.unit.cpp \
		   tests/tuple.unit.cpp \
		   tests/camera.unit.cpp \
		   tests/sphere.unit.cpp \
		   tests/fileHandler.unit.cpp

main: main.cpp $(PROGRAM_FILES)
	$(CC) -o main main.cpp $(PROGRAM_FILES)

test: $(PROGRAM_FILES) $(TEST_FILES)
	$(CC) -o test tests/tests.cpp vector/vector.o plane/plane.o tuple/tuple.o camera/camera.o fileHandler/fileHandler.o world/world.o sphere/sphere.o

clean:
	rm $(PROGRAM_FILES)

vector/vector.o: vector/vector.cpp vector/vector.h tuple/tuple.o
	$(CC) -c vector/vector.cpp -o vector/vector.o

plane/plane.o: plane/plane.cpp plane/plane.h $(SHAPE_FILES)
	$(CC) -c plane/plane.cpp -o plane/plane.o

sphere/sphere.o: sphere/sphere.cpp sphere/sphere.h $(SHAPE_FILES)
	$(CC) -c sphere/sphere.cpp -o sphere/sphere.o

tuple/tuple.o: tuple/tuple.cpp tuple/tuple.h
	$(CC) -c tuple/tuple.cpp -o tuple/tuple.o

camera/camera.o: camera/camera.cpp camera/camera.h fileHandler/fileHandler.o
	$(CC) -c camera/camera.cpp -o camera/camera.o

fileHandler/fileHandler.o: fileHandler/fileHandler.cpp fileHandler/fileHandler.h
	$(CC) -c fileHandler/fileHandler.cpp -o fileHandler/fileHandler.o

world/world.o: world/world.cpp world/world.h $(SHAPE_FILES)
	$(CC) -c world/world.cpp -o world/world.o