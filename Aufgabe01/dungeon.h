
typedef enum{
	/* Enum fuer die Himmelsrichtungen. 
 	* Es wird NORD = 1, SUED = 2, WEST= 3 und OST = 4 gesetzt.
	*/ 
	NORD=1, SUED, WEST, OST
} richtung;

typedef struct liste{
	char item[256];
	struct liste *next;
} liste;

typedef struct{
	char aktueller_raum[256];
	liste *inventar;
} spielstand;

typedef struct{
	char name[256];
	char item[256];
	char beschreibung[1024];
} ausgang;

typedef struct{
	char beschreibung[1024];
	ausgang * ausgang_norden;
	ausgang * ausgang_sueden;
	ausgang * ausgang_westen;
	ausgang * ausgang_osten;
	liste *gegenstaende;
} raum;


/* Zur Verwaltung der Liste haben wir folgende Funktionen verwendet. Sollten Sie einige davon
* nicht benötigen, können Sie diese einfach löschen. Sie können natürlich auch weitere Funktionen
* zur Verwaltung der Liste schreiben. Wir empfehlen Teile Ihres Codes von Tag 7 erneut zu verwenden.
*/

liste* element_einfuegen(liste *start, char *to_add);
int in_liste(liste *start, char *vergleich);
void liste_freigeben(liste *start);


/* Hilfsfunktionen:
 * Die Funktion richtung_to_string wandelt ein Element des Enums für Richtungen in den passenden
 * String um. Achten Sie darauf, dass r_string genug Speicher bereitstellen muss!
 * Die Funktion print_ausgang übernimmt die Ausgabe dessen, was man in eine bestimmte Richtung
 * sieht.
 */

int befehlsverarbeitung(char *befehl, char *gegenstand, spielstand *st);
void richtung_to_string(richtung r, char* r_string);
void print_ausgang(int i, char* ort);

/*
 * Funktionen, die bereits aufgerufen werden, aber nicht implementiert sind:
 */

int lade_spielstand(spielstand *st);
int speichere_spielstand(spielstand st);
int gehe(richtung r, spielstand *st);
void inv(liste *start);
int nimm(char *gegenstand, spielstand *st);
int guck(spielstand *st);

/*
 * Platz für Ihre Funktionen
 */

liste * createList(char * item);
void addToList(liste * start, liste * toAdd);
void printList(liste * start);
int isInList(liste * start, char * itemToCheck);


/* Ausgabestrings:
*  
* Damit Sie nicht alle Ausgaben abtippen müssen, finden Sie hier einige vordefiniert Strings, die 
* Sie verwenden sollten. Diese sind ausnahmsweise global. Einige dieser Strings beinhalten Platzhalter
* (z.B. %s) - achten Sie bei der Verwendung darauf dann auch entsprechenden Inhalt anzugeben.
* 
* Beispiel für die Verwendung:
* char *raum = zelle;
* printf(MEIN_STANDORT, zelle);
*/

const char *INVENTAR_LEER = "In Deinen Taschen findest Du nur ein wenig Dreck.\n";
const char *INVENTAR_VOLL = "In Deinen Taschen findest Du:\n\t";

const char *ENDLICH_FREI = "Du bist in die rettende FREIHEIT entkommen und willst NIE wieder zurück.\n";
const char *SCHON_FREI = "Du hörst das gemeine Lachen von Du-weißt-schon-wem und bist Dir fast sicher, "
			"dass Du nicht zurück möchtest.\nSolltest Du doch zurückkehren wollen tippe"
			"\n\tmake neustart\num in Deine Zelle zurückzukehren.\n";

const char *RAUMWECHSEL = "Du verlässt den Raum \'%s\' in Richtung %s und betritts nun den Raum \'%s\'.\n";
const char *BENOETIGT_GEGENSTAND = "Um diesen Raum zu betreten benötigst Du eine(n) %s.\n";
const char *WAND = "Im %s läufst  Du vor eine Wand. AUA!\n";

const char *MEIN_STANDORT = "Du befindest Dich im Raum \'%s\'.\n";
const char *GUCK_GEGENSTAND = "Du siehst hier folgende Gegenstände:\n\t";
const char *GUCK_AUSGAENGE = "Du schaust Dich um und siehst:\n";
const char *GUCK_NORD = "\t Im Norden siehst Du:   %s\n";
const char *GUCK_SUED = "\t Im Süden siehst Du:    %s\n";
const char *GUCK_WEST = "\t Im Westen siehst Du:   %s\n";
const char *GUCK_OST = "\t Im Osten siehst Du:    %s\n";

const char *ERR_RAUM_NICHT_DA = "Du befindest Dich in einem Raum, den es nicht gibt...\n";
const char *ERR_GEGENSTAND_IN_INVENTAR = "Dieser Gegenstand ist bereits in Deinen Taschen!\n";
const char *ERR_GEGENSTAND_NICHT_IN_RAUM = "Du kannst nichts nehmen, was es nicht gibt!\n";
