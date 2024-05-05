CXX = g++
CXXFLAGS = -Wall -Wextra -pedantic -std=c++2a

OBJS = Zombie.o Game.o main.o HairMetalZombie.o RegularZombie.o sun.o Board.o Cell.o

HEADERS = Zombie.h Game.h HairMetalZombie.h RegularZombie.h sun.h Board.h Cell.h

LIBS = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

all: PlantVsZombi clean

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

PlantVsZombi: $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $@ $(LIBS)

.PHONY: clean
clean:
	rm -f *.o
