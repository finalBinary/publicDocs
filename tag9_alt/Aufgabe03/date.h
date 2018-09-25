/* Schreiben Sie eine Struktur date, welche die Integer day, month und year
 * beinhaltet.
 */
 
typedef struct {
	unsigned short year;
	unsigned short month;
	unsigned short day;
} date; 


/* Implementieren Sie diese Funktionen in date.c */
void print_date(date d);
int is_before(date a, date b);
