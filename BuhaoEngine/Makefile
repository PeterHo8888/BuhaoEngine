CXX = g++
CXXFLAGS = -Wall -Wextra -fpermissive
LDFLAGS = -lSDL2 -lSDL2_image

BUILD_DIR = build

SRCS = $(wildcard *.cc)
OBJS = $(patsubst %.cc,$(BUILD_DIR)/%.o,$(SRCS))

AR = ar

$(BUILD_DIR)/libbuhao.a: $(OBJS)
	$(AR) rcs $@ $^

$(BUILD_DIR)/%.o: %.cc %.h
	mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

$(BUILD_DIR)/%.o: %.cc
	mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

.PHONY: clean
clean:
	rm -rf $(BUILD_DIR)
