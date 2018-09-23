execName = start
cMainFileName = main
dateFileName = date
carFileName = car


$(execName): $(cMainFileName).o $(dateFileName).o $(dateFileName).h $(carFileName).o $(carFileName).h
	gcc  -std=c99 -Wall -o $(execName) $(cMainFileName).o $(dateFileName).o $(carFileName).o

$(cMainFileName).o: $(cMainFileName).c
	gcc -c -std=c99 -Wall $(cMainFileName).c

$(dateFileName).o: $(dateFileName).c $(dateFileName).h
	gcc -c -std=c99 -Wall $(dateFileName).c

$(carFileName).o: $(carFileName).c $(carFileName).h
	gcc -c -std=c99 -Wall $(carFileName).c

test:
	gcc $(cMainFileName).c $(testName).c -o $(testName) -Wall -std=c99 -g -fprofile-arcs -ftest-coverage -pthread -lcheck -lrt -lm -lsubunit

clean:
	rm *.o $(execName) 

