.PHONY: all clean run runt

all: exe/main.exe

docs:
	@doxygen Doxyfile

run: 
	@exe/main.exe

runt:
	@exe/main.exe -t

clean:
	@rmdir o /s /q
	@rmdir exe /s /q
	@mkdir o
	@mkdir exe

FILES:= o/main.o o/solver.o o/tester.o o/custom.o

DED_FLAGS := -Wshadow -Winit-self -Wredundant-decls -Wcast-align -Wundef -Wfloat-equal -Winline -Wunreachable-code -Wmissing-declarations -Wmissing-include-dirs -Wswitch-enum -Wswitch-default -Wmain -Wextra -Wall -g -pipe -fexceptions -Wcast-qual -Wconversion -Wempty-body -Wformat-security -Wformat=2 -Wignored-qualifiers -Wlogical-op -Wno-missing-field-initializers -Wpointer-arith -Wstack-usage=8192 -Wstrict-aliasing -Wtype-limits -Wwrite-strings -Werror=vla -D_DEBUG -D_EJUDGE_CLIENT_SIDE

CFLAGS:= -I ./headers $(DED_FLAGS) -Wno-unused-parameter

exe/main.exe: $(FILES)
	@gcc $(FILES) -o exe/main.exe

o/%.o: source/%.c
	@gcc $< $(CFLAGS) -c -o $@
