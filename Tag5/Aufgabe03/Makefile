execName = start
#asmFileName = main
cMainFileName = main

$(execName): $(cMainFileName).o 
	gcc -m32 -o $(execName) -std=c99 -Wall $(cMainFileName).o most_frequent2.h

$(cMainFileName).o: $(cMainFileName).c 
	gcc -m32 -c most_frequent2.h $(cMainFileName).c


clean:
	rm *.o $(execName)

