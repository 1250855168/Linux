

src=$(wildcard ./src/*.c )

obj=$(patsubst %.c,%.o,${src})

cc = gcc

ALL:a.out

./src%.o:./src%.c
	${cc} -c $< -o $@

a.out: ${obj}
	${cc} main.c $^ -o $@ -I include

clean:
	-rm -rf ${obj} a.out

.PHONY:clean ALL
