CC = g++
CFLAGS = -std=c++11
LFLAGS = -lglfw3 -lGL -lGLU -lGLEW -lX11 -lXxf86vm -lXrandr -lpthread -lXi

SRCDIR = src


SOURCES = $(wildcard $(SRCDIR)/*.cpp)

all: dim4

clean:
	rm -f dim4

dim4: $(SOURCES)
	$(CC) $(CFLAGS) $(SOURCES) $(LFLAGS) -o dim4
