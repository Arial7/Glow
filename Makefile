CC = g++

INTERNAL_INCLUDE_PATHS = -I./ -I./src/components -I./src/graphics -I./src/maths -I./src/utils

DEFINES = -DGL3_PROTOTYPES=1

CCFLAGS = -Wall -std=c++11 -I/usr/include/freetype2 $(INTERNAL_INCLUDE_PATHS) $(DEFINES) -g
LDFLAGS = -lSDL2 -lSDL2_image -lGL -lGLU -lGLEW `pkg-config --cflags --libs ftgl`

SRCDIR = src/
OBJDIR = obj/

SRC = $(shell find src/ -type f -name '*.cpp')
OBJ = $(SRC:src/%.cpp=obj/%.o)

EXECUTABLE = glow 


$(EXECUTABLE):$(OBJ)
	$(CC) $(OBJ) -o $(EXECUTABLE) $(LDFLAGS)

obj/%.o:src/%.cpp
	@mkdir -p "$(@D)"
	$(CC) -c $(CCFLAGS) $< -o $@

clean:
	rm -f $(OBJ) $(EXECUTABLE)
