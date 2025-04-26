CC = gcc
TARGET = listas.exe
SRC = listas.c

all: $(TARGET)
	$(TARGET)

$(TARGET): $(SRC)
	$(CC) -o $(TARGET) $(SRC)

clean:
	del /Q $(TARGET)
