CXX = g++
CXXFLAGS = -Wall -Wextra -fpermissive

BUILD_DIR = build

SRCS = $(wildcard *.cc) $(wildcard **/*.cc)
OBJS = $(patsubst %.cc,$(BUILD_DIR)/%.o,$(SRCS))

AR = ar

$(BUILD_DIR)/libbuhao.a: $(OBJS)
	$(AR) rcs $@ $^

$(BUILD_DIR)/%.o: %.cc %.h
	@mkdir -p $(shell dirname $@)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

$(BUILD_DIR)/%.o: %.cc
	@mkdir -p $(shell dirname $@)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

.PHONY: clean
clean:
	rm -rf $(BUILD_DIR)
