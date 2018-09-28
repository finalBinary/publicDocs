execName = start
#asmFileName = main
cMainFileName = main
testName = toUpper_tests

$(execName): $(cMainFileName).o 
	gcc -m32 -std=c99 -o $(execName) -std=c99 -Wall $(cMainFileName).o

$(cMainFileName).o: $(cMainFileName).c 
	gcc -m32 -c -std=c99 $(cMainFileName).c

test:
	gcc $(cMainFileName).c $(testName).c -o $(testName) -Wall -std=c99 -g -fprofile-arcs -ftest-coverage -pthread -lcheck -lrt -lm -lsubunit

clean:
	rm *.o $(execName)