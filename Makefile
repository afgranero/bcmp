TARGET = bcmp

BINDIR = /usr/local/bin

# Build the program
$(TARGET): bcmp.c
	cc bcmp.c -o $(TARGET)

install: $(TARGET)
	cp $(TARGET) $(BINDIR)/

uninstall:
	mkdir -p /tmp/bcmp_trash
	mv $(BINDIR)/$(TARGET) /tmp/bcmp_trash/$(TARGET).$(shell date +%F_%H-%M-%S)
	@echo "File moved to /tmp/bcmp_trash/ instead of deleted for safety."

clean:
	rm -f $(TARGET)

