# OSX SUCKS BUT I STILL HAVE TO USE IT

CXX = g++-13
CXXFLAGS = -F/Library/Frameworks -std=c++20
CXXLIBS = -framework SDL2 -framework SDL2_image -framework SDL2_ttf

TARGET = main.cpp #EXAMPLE !!!
TARGETS = $(wildcard src/*.cpp)
OBJS = $(TARGETS:.cpp=.o)

linea.o: $(TARGETS)
	$(CXX) $(TARGETS) $(CXXFLAGS) $(CXXLIBS) -c 
	$(eval OBJS = $(wildcard *.o))
	ld -r $(OBJS) -o linea.o 

main:
	$(CXX) main.cpp linea.o -o main $(CXXFLAGS) $(CXXLIBS)         

clean:
	rm *.o main