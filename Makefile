CXX = g++
EXEC = prog
INCLUDE = -Iinclude -Iheader
LIB = -Llib -lsfml-graphics -lsfml-window -lsfml-system
SRC = $(wildcard src/*.cpp)
OBJ = $(SRC:.cpp=.o)

all : $(EXEC)

%.o : %.cpp
	$(CXX) -o $@ -c $< $(INCLUDE)

$(EXEC) : $(OBJ)
	$(CXX) -o bin/$(EXEC) $(OBJ) $(LIB)