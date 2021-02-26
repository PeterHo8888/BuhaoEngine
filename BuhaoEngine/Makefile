CXX = g++
CXXFLAGS = -Wall -Wextra
LDFLAGS = -lSDL2 -lSDL2_image

SRCS = $(wildcard *.cc)
OBJS = $(patsubst %.cc,%.o,$(SRCS))

libbuhao.a: $(OBJS)
	ar rcs $@ $^

%.o: %.cc %.h
	$(CXX) $(CXXFLAGS) -c -o $@ $<

%.o: %.cc
	$(CXX) $(CXXFLAGS) -c -o $@ $<

.PHONY: clean
clean:
	rm -rf *.o *.a
