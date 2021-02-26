CXX = g++
CXXFLAGS = -Wall -Wextra
LDFLAGS = -LBuhaoEngine -lSDL2 -lSDL2_image -lbuhao

SRCS = $(wildcard *.cc)
OBJS = $(patsubst %.cc,%.o,$(SRCS))

.PHONY: all clean
all:
	$(MAKE) -C BuhaoEngine
	$(MAKE) app

app: $(OBJS) BuhaoEngine/libbuhao.a
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

%.o: %.cc %.h
	$(CXX) $(CXXFLAGS) -c -o $@ $<

%.o: %.cc
	$(CXX) $(CXXFLAGS) -c -o $@ $<

clean:
	$(MAKE) -C BuhaoEngine clean
	rm -rf *.o app
