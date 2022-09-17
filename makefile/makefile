

src=$(wildcard ./src/*.c )

obj=$(patsubst %.c,%.o,${src})

ALL:a.out

VPATH=include:src
vpath %.cpp src
vpath %.h include

./src%.o:./src%.c
	gcc -c $< -o $@

a.out: ${obj}
	gcc main.c $^ -o $@ -I include

clean:
	-rm -rf ${obj} a.out

