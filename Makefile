TARGET = ray?
CC = gcc

SRC_PATH = ./src
OBJ_PATH = ./obj

SRC = $(shell find $(SRC_PATH) -type f -name '*.c')
OBJ = $(patsubst $(SRC_PATH)/%.c, $(OBJ_PATH)/%.o,$(SRC))

CFLAGS = -O2
LDFLAGS = -lm -lJudy -lSDL3

$(TARGET): $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	mkdir -p $(@D)
	$(CC) -c -o $@ $< $(CFLAGS)

clean: 
	rm -f $(OBJ)
	rm -f $(TARGET)
