CC = g++

CCFLAGS = -Wall -std=c++11 -I/usr/include/freetype2 -DGL3_PROTOTYPES=1 -march=native -g
LDFLAGS = -lSDL2 -lSDL2_image -lGL -lGLU -lGLEW `pkg-config --cflags --libs ftgl`

SRCDIR = src/
OBJDIR = obj/

SRC = $(wildcard $(SRCDIR)*.cpp)
OBJ = $(addprefix obj/,$(notdir $(SRC:.cpp=.o)))

EXECUTABLE = glow 


$(EXECUTABLE):$(OBJ)
	$(CC) $(OBJ) -o $(EXECUTABLE) $(LDFLAGS)

run:$(EXECUTABLE)
	./3d &	

obj/%.o:src/%.cpp

	$(CC) -c $(CCFLAGS) $< -o $@

clean:
	rm -f $(OBJ) $(EXECUTABLE)
