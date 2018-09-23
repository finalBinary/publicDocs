struct date {
	unsigned short year;
	unsigned short month;
	unsigned short day;
};

void printDate(struct date * ptr);
struct date * readDate();
struct date * readDateLine();
struct date * parseDate(char * dateStr);
int is_before(struct date a, struct date b);