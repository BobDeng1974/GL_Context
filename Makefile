SRCS=$(wildcard src/*.cpp)
OBJS=$(SRCS:.cpp=.o)

all: $(OBJS)
	mv *.o ./bin

%.o: %.cpp
	g++ -c $<

clean:
	cd bin && rm *.o