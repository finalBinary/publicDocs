struct date {
	unsigned short year;
	unsigned short month;
	unsigned short day;
};

void printDate(struct date * ptr);
int is_before(struct date a, struct date b);