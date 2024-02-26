# OSX SUCKS BUT I STILL HAVE TO USE IT

CXX = g++-13
CXXFLAGS = -F/Library/Frameworks
CXXLIBS = -framework SDL2 -framework SDL2_image

TARGET = main.cpp #EXAMPLE !!!
TARGETS = $(wildcard src/*.cpp)
OBJS = 

linea.o: $(TARGETS)
	$(CXX) $(TARGETS) $(CXXFLAGS) $(CXXLIBS) -c 
	$(eval OBJS = $(wildcard *.o))
	ld -r $(OBJS) -o linea.o 

clean:
	rm *.o 