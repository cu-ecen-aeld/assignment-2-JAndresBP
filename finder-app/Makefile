CC := gcc
CROSS_COMPILE := 
TARGET_EXEC := writer
#BUILD_DIR := ./build

SRCS := writer.c
#OBJS := $(SRCS:%=$(BUILD_DIR)/%.o)
OBJS := writer.o

COMPILER = $(CROSS_COMPILE)$(CC)

$(TARGET_EXEC): $(OBJS)
	$(COMPILER) $(OBJS) -o $@ $(LDFLAGS)

$(OBJS): $(SRCS)
	mkdir -p $(dir $@)
	$(COMPILER) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -f *.o writer *.elf *.map
#	rm -r $(BUILD_DIR)
