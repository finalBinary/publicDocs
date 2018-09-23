
struct form {
	unsigned int subject: 2;
	unsigned int year: 4;
	unsigned int rating: 3;
	char remarks[121];
};

enum {Informatik, Mathematik, Physik};

void setSubject(struct form survey, char * subject);
void printForm(struct form survey);
