CFLAGS := -Wall -Wextra

TARGET := test

SRC := $(wildcard get_next_line*/*.c)# $(wildcard tests_bonus/*.c)

all:
	cc -g -lm -w ${SRC} test.c -o ${TARGET}
#	./${TARGET}
	
d:
	cc -g ${CFLAGS} -D BUFFER_SIZE=10 ${SRC} test.c -o ${TARGET}
#	./${TARGET} | cat -e

clean:
	rm -f test

show:

val:
	cc -g ${CFLAGS} -D BUFFER_SIZE=10 ${SRC} test.c -o ${TARGET}
	valgrind -s --leak-check=yes --show-leak-kinds=all --track-origins=yes ./test

run:
	./${TARGET}


#BONUSFILES := $(wildcard *bonus.c)
#SRCFILES := $(wildcard ft*.c)

#%.o : %.c
#	cc -c $(CFLAGS) $< -o $@

#libft: $(SRCFILES) clean
#	cc $(CFLAGS) -c $(SRCFILES) -o %.o