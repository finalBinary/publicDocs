execName = start
cMainFileName = main

$(execName): $(cMainFileName).o
	gcc -g -std=c99 -Wall -o $(execName) $(cMainFileName).o

$(cMainFileName).o: $(cMainFileName).c
	gcc -g -c -std=c99 -Wall $(cMainFileName).c

test:
	gcc $(cMainFileName).c $(testName).c -o $(testName) -Wall -std=c99 -g -fprofile-arcs -ftest-coverage -pthread -lcheck -lrt -lm -lsubunit

clean:
	rm *.o $(execName)
