BUILD_DIR = apps
GAMES = tic-tac-toe excaball
#TARGETS = $(patsubst %,$(BUILD_DIR)/%,$(GAMES))

.PHONY: all clean BuhaoEngine/build/libbuhao.a $(GAMES)

all: BuhaoEngine/build/libbuhao.a $(GAMES)

BuhaoEngine/build/libbuhao.a:
	$(MAKE) -C BuhaoEngine

$(GAMES):
	mkdir -p $(BUILD_DIR)
	$(MAKE) -C $@

clean:
	$(MAKE) -C BuhaoEngine clean
	for f in $(GAMES); do \
		$(MAKE) -C $$f clean; \
	done
	rm -rf $(BUILD_DIR)
