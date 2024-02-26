# OSX SUCKS BUT I STILL HAVE TO USE IT

CXX = g++-13
CXXFLAGS = -F/Library/Frameworks
CXXLIBS = -framework SDL2 -framework SDL2_image

TARGET = main.cpp #EXAMPLE !!!
TARGETS = src/*.cpp

%.o: %.cpp
	$(CXX) $> $(CXXFLAGS) $(CXXLIBS) -o $@.o -c 

linea.o: $(TARGETS)
	$(eval OBJS = src/*.o)
	$(CXX) $(CXXFLAGS) $(CXXLIBS) $(OBJS) -o linea.o -c 
