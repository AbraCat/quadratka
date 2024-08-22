all: main.exe

run: main.exe
	main.exe

FILES:= o/main.o o/solver.o o/tester.o

CFLAGS:= -I ./headers

main.exe: $(FILES)
	gcc $(FILES) -o main.exe

o/%.o: source/%.c
	gcc $< $(CFLAGS) -c -o $@



# all: exe/main.exe

# run: exe/main.exe
# 	cd exe
# 	main.exe

# FILES:= o/main.o o/solver.o o/tester.o

# CFLAGS:= -I ./headers

# exe/main.exe: $(FILES)
# 	gcc $(FILES) -o exe/main.exe

# o/%.o: source/%.c
# 	gcc $< $(CFLAGS) -c -o $@