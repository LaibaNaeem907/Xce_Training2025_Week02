SCRIPTS = $(wildcard *.sh)
INSTALL_DIR = /usr/local/bin

syntax:
	@echo "Checking syntax..."
	@for file in $(SCRIPTS); do \
		bash -n $$file || exit 1; \
	done
	@echo "All scripts passed syntax check!"

install: syntax
	@echo "Installing scripts to $(INSTALL_DIR)..."
	install -m 755 $(SCRIPTS) $(INSTALL_DIR)
	@echo "Scripts installed successfully!"
