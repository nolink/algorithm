
random_test: random.o random_test.o
	g++ -g random.o random_test.o -o test
random.o: random.h random.c
	g++ -g -c random.c
random_test.o: random_test.c
	g++ -g -c random_test.c
clean:
	rm -f *.exe *.o