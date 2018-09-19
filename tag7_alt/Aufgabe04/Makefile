execName = start
cMainFileName = main

$(execName): $(cMainFileName).o
	gcc -m32 -o $(execName) -std=c99 -Wall $(cMainFileName).c

$(cMainFileName).o: $(cMainFileName).c
	gcc -m32 -c -std=c99 $(cMainFileName).c

test:
	gcc $(cMainFileName).c $(testName).c -o $(testName) -Wall -std=c99 -g -fprofile-arcs -ftest-coverage -pthread -lcheck -lrt -lm -lsubunit

clean:
	rm *.o $(execName)

