.PHONY: all clean run runt

all: exe/main.exe

docs:
	doxygen Doxyfile

run: 
	exe/main.exe

runt:
	exe/main.exe -t

clean:
	rmdir o /s /q
	rmdir exe /s /q
	mkdir o
	mkdir exe

FILES:= o/main.o o/solver.o o/tester.o o/custom.o

CFLAGS:= -I ./headers

exe/main.exe: $(FILES)
	gcc $(FILES) -o exe/main.exe

o/%.o: source/%.c
	gcc $< $(CFLAGS) -c -o $@