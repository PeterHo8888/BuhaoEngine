BUILD_DIR = apps
GAMES_DIR = games
GAMES = tic-tac-toe excaball
#TARGETS = $(patsubst %,$(BUILD_DIR)/%,$(GAMES))

.PHONY: all clean BuhaoEngine/build/libbuhao.a $(GAMES)

all: BuhaoEngine/build/libbuhao.a $(GAMES)

BuhaoEngine/build/libbuhao.a:
	$(MAKE) -C BuhaoEngine

$(GAMES):
	mkdir -p $(BUILD_DIR)
	$(MAKE) -C $(GAMES_DIR)/$@

clean:
	$(MAKE) -C BuhaoEngine clean
	for f in $(GAMES); do \
		$(MAKE) -C $(GAMES_DIR)/$$f clean; \
	done
	rm -rf $(BUILD_DIR)
