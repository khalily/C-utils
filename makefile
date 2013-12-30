cc = gcc

all: type_value

type_value: type_value.c
	${cc} -o type_value type_value.c -lm

clean:
	rm -rf type_value
