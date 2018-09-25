execName = start
cMainFileName = tiere
dateFileName = date
testName = date_tests

$(execName): $(cMainFileName).o $(dateFileName).o $(dateFileName).h
	gcc  -std=c99 -Wall -o $(execName) $(cMainFileName).o $(dateFileName).o

$(cMainFileName).o: $(cMainFileName).c
	gcc -c -std=c99 -Wall $(cMainFileName).c

$(dateFileName).o: $(dateFileName).c
	gcc -c -std=c99 -Wall $(dateFileName).c

test:
	gcc $(dateFileName).c $(testName).c -o $(testName) -Wall -std=c99 -g -fprofile-arcs -ftest-coverage -pthread -lcheck -lrt -lm -lsubunit

clean:
	rm *.o $(execName) 

