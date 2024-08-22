.PHONY: all clean run

all: exe/main.exe

run: 
	exe/main.exe

clean:
	rmdir o /s /q
	rmdir exe /s /q
	mkdir o
	mkdir exe

FILES:= o/main.o o/solver.o o/tester.o

CFLAGS:= -I ./headers

exe/main.exe: $(FILES)
	gcc $(FILES) -o exe/main.exe

o/%.o: source/%.c
	gcc $< $(CFLAGS) -c -o $@