CXX = g++
CXXFLAGS = -Wall -Wextra -I../

BUILD_DIR = build

LDFLAGS = -L../BuhaoEngine/$(BUILD_DIR) -lSDL2 -lSDL2_image -lSDL2_mixer -lbuhao

SRCS = $(wildcard *.cc)
OBJS = $(patsubst %.cc,$(BUILD_DIR)/%.o,$(SRCS))

TARGET = ../apps/tic-tac-toe

.PHONY: all clean
all:
	$(MAKE) ../apps/tic-tac-toe

$(TARGET): $(OBJS) ../BuhaoEngine/$(BUILD_DIR)/libbuhao.a
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

$(BUILD_DIR)/%.o: %.cc %.h
	mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

$(BUILD_DIR)/%.o: %.cc
	mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

clean:
	rm -rf $(BUILD_DIR)
