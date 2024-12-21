CC := gcc

CFLAGS := -std=c99 -Wall -Werror -Wpedantic -Wextra -Wfloat-equal -Wfloat-conversion -Wvla -g -MMD

SRCS := main.c list.c
OBJS := main.o list.o

DEPS := $(OBJS:.o=.d)

all: app.exe

app.exe: $(OBJS)
	$(CC) $(OBJS) -o $@ $(LDFLAGS)

$(OUT_DIR)/%.o : $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: build run clean

build: CFLAGS += -O2
build: app.exe

run: app.exe
	./app.exe

clean:
	$(RM) -- -rf *.exe *.out *.d *.o out.txt

-include $(DEPS)
