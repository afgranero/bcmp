TARGET = bcmp

BINDIR = /usr/local/bin

# Build the program
$(TARGET): bcmp.c
	cc bcmp.c -o $(TARGET)

.PHONY: install
install: $(TARGET)
	cp $(TARGET) $(BINDIR)/

.PHONY: uninstall
uninstall:
	mkdir -p /tmp/bcmp_trash
	mv $(BINDIR)/$(TARGET) /tmp/bcmp_trash/$(TARGET).$(shell date +%F_%H-%M-%S)
	@echo "File moved to /tmp/bcmp_trash/ instead of deleted for safety."

.PHONY: clean
clean:
	rm -f $(TARGET)

