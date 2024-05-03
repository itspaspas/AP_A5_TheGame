CXX = g++
CXXFLAGS = -Wall -Wextra -pedantic -std=c++2a

OBJS = Zombi.o Game.o main.o HairMetalZombie.o RegularZombie.o

HEADERS = Zombi.h Game.h HairMetalZombie.h RegularZombie.h

LIBS = -lsfml-graphics -lsfml-window -lsfml-system

all: PlantVsZombi clean

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

PlantVsZombi: $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $@ $(LIBS)

.PHONY: clean
clean:
	rm -f *.o
