CC=g++
CPPINCLUDE= -I. -I./src
CFLAGS=-Wall -Wno-write-strings -std=c++11 -lpthread -lgtest ${CPPINCLUDE}
SRC=src/word_count.cc
MAIN=src/main.cc
TEST1=test/test_tsy.cc
TEST2=test/test_tmh.cc
TEST3=test/test_gzh.cc
TEST4=test/test_yl.cc

WCpro: ${SRC} ${MAIN}
	${CC} ${CFLAGS} ${SRC} ${MAIN} -o WCpro

test_tsy: ${SRC} ${TEST1}
	${CC} ${CFLAGS} ${SRC} ${TEST1} -o test_tsy

test_tmh: ${SRC} ${TEST2}
	${CC} ${CFLAGS} ${SRC} ${TEST2} -o test_tmh

test_gzh: ${SRC} ${TEST3}
	${CC} ${CFLAGS} ${SRC} ${TEST3} -o test_gzh

test_yl: ${SRC} ${TEST4}
	${CC} ${CFLAGS} ${SRC} ${TEST4} -o test_yl

.PHONY : clean
clean :
	-rm -f WCpro result.txt test_*
