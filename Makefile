CXX = g++
CXXFLAGS = -Wall -Wextra
LDFLAGS = -LBuhaoEngine -lSDL2 -lSDL2_image -lbuhao

SRCS = $(wildcard *.cc)
OBJS = $(patsubst %.cc,%.o,$(SRCS))

app: $(OBJS)
	$(MAKE) -C BuhaoEngine
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

%.o: %.cc %.h
	$(CXX) $(CXXFLAGS) -c -o $@ $<

%.o: %.cc
	$(CXX) $(CXXFLAGS) -c -o $@ $<

.PHONY: clean
clean:
	rm -rf *.o app
