BUILD_DIR = apps
GAMES_DIR = games
GAMES = $(wildcard $(GAMES_DIR)/*)

.PHONY: all clean
.PHONY: switch
.PHONY: $(GAMES)

all:
	@TARGET_MK=Makefile $(MAKE) $(GAMES)

switch:
	@TARGET_MK=Makefile-switch $(MAKE) $(GAMES)

$(GAMES):
	@mkdir -p $(BUILD_DIR)
	@$(MAKE) -C $@ -f $(TARGET_MK)

switch-%:
	@TARGET_MK=Makefile-switch $(MAKE) _$*
	rm -rf $(BUILD_DIR)-switch

clean:
	@TARGET_MK=Makefile $(MAKE) _clean
	rm -rf $(BUILD_DIR)

_clean:
	$(MAKE) -C BuhaoEngine clean -f $(TARGET_MK)
	for f in $(GAMES); do \
		$(MAKE) -C $$f -f $(TARGET_MK) clean; \
	done
