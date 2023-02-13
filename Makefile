FLAGS= -Wall -pedantic -std=c++17 -iquote inc

__start__: quiz
	./quiz 

quiz: obj/main.o obj/question.o
	g++ -o ./quiz obj/main.o obj/question.o

obj:
	mkdir obj

obj/main.o: src/main.cpp inc/question.hh inc/size.hh
	g++ -c ${FLAGS} -o obj/main.o src/main.cpp

obj/question.o: inc/question.hh src/question.cpp inc/size.hh
	g++ -c ${FLAGS} -o obj/question.o src/question.cpp

clean:
	rm -f ./quiz obj/*

