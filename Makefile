CXX = g++
CXXFLAGS = -Wall -Wextra

BUILD_DIR = build

LDFLAGS = -LBuhaoEngine/$(BUILD_DIR) -lSDL2 -lSDL2_image -lSDL2_mixer -lbuhao

SRCS = $(wildcard *.cc)
OBJS = $(patsubst %.cc,$(BUILD_DIR)/%.o,$(SRCS))

.PHONY: all clean
all:
	$(MAKE) -C BuhaoEngine
	$(MAKE) app

app: $(OBJS) BuhaoEngine/$(BUILD_DIR)/libbuhao.a
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

$(BUILD_DIR)/%.o: %.cc %.h
	mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

$(BUILD_DIR)/%.o: %.cc
	mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

clean:
	$(MAKE) -C BuhaoEngine clean
	rm -rf $(BUILD_DIR)
