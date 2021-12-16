CFLAGS = -g -Wall
LDFLAGS = -lSDL2 -lSDL2_image
SOURCES = $(wildcard *.cpp) $(wildcard */*.cpp)
EXEC = sdltest
OBJS = $(patsubst %.cpp,%.o,$(SOURCES))


$(EXEC): $(OBJS)
	$(CXX) $(LDFLAGS) $(CFLAGS) -o $(EXEC) $(OBJS)

%.o: %.cpp Makefile
	$(CXX) $(CFLAGS) -c -o $@ $<

clean:
	$(RM) $(OBJS) $(DEPENDS)