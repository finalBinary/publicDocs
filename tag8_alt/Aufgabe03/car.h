#include "date.h"

#define MAX_LEN 30

struct car {
	char brand[MAX_LEN];
	char model[MAX_LEN];
	struct date constYear;
	unsigned int org: 1;
};

enum {Kmobi, Limousine, Minivan, Kleinwagen};

void printCar(struct car * ptr);
struct car * readCar();
struct car * readCarLine(char * line);