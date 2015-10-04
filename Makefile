CC = g++

DEFINES = -DGLOW_PRESET_2D -DGLOW_DEBUG

DEFINES_PRODUCTION = -DGL3_PROTOTYPES=1

CCFLAGS = -Wall -std=c++11 -I/usr/include/freetype2  $(DEFINES) -g

CCFLAGS_PRODUCTION = -Wall -std=c++11 -I/usr/include/freetype2  $(DEFINES-PRODUCTION) -O2


LDFLAGS = -lglfw -lGL -lGLU -lGLEW

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
