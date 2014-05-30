CC = g++
CFLAGS = -std=c++11
LFLAGS = -lglfw3 -lGL -lGLU -lX11 -lXxf86vm -lXrandr -lpthread -lXi

all: dim4

clean:
	rm -f dim4

dim4:
	$(CC) $(CFLAGS) main.cpp $(LFLAGS) -o dim4
