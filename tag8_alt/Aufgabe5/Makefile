execName = start
cMainFileName = main
dateFileName = form

$(execName): $(cMainFileName).o $(dateFileName).o $(dateFileName).h
	gcc  -std=c99 -Wall -o $(execName) $(cMainFileName).o $(dateFileName).o

$(cMainFileName).o: $(cMainFileName).c
	gcc -c -std=c99 -Wall $(cMainFileName).c

$(dateFileName).o: $(dateFileName).c
	gcc -c -std=c99 -Wall $(dateFileName).c

test:
	gcc $(cMainFileName).c $(testName).c -o $(testName) -Wall -std=c99 -g -fprofile-arcs -ftest-coverage -pthread -lcheck -lrt -lm -lsubunit

clean:
	rm *.o $(execName) 