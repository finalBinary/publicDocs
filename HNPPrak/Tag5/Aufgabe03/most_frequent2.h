/* In diesem Array sollen Sie jedes im Text enthaltene Wort einmal speichern
 * Wir gehen davon aus, dass der Text maximal 80 Worte mit je maximal 80 Zeichen
 * enthaelt. Ausnahmsweise ist es global.
 *
 * Mit Wort meinen wir in der gesamten Aufgabe immer ein Wort oder eines der genannten
 * Sonderzeichen!
 */

char words[80][81];


/* Funktionsprototypen
 *
 * extract_and_count soll die Worte aus source im Array words speichern, die Anzahl der 
 * verschiedenen Worte zurueckgeben und im Array count, speichern, wie oft
 * jedes Wort im String enthalten ist, wobei die Indizes der Arrays count und
 * words korrespondieren.
 * 
 * Vereinfachend können Sie davon ausgehen, dass niemals zwei Leerzeichen hintereinander stehen.
 * Sie wissen allerdings nicht, ob vor oder nach einem Sonderzeichen Leerzeichen stehen oder nicht.
 *
 * get_most_frequent_word gibt den Index des häufigsten Wortes zurück. Sollte
 * es mehrere häufigste Worte geben, so ist egal, welches davon zurückgegeben wird.
 * 
 * Die Funktion print soll das Wort ausgeben, welches am häufigsten im Text vorkommt
 * und wird nicht mittels Unittests getestet.
 *
 * Es ist wahrscheinlich hilfreich weitere Funktionen zu schreiben.
 */
 
int extract_and_count(char *source,  int *count);
void print(int diff_words, int *count);
int get_most_frequent_word(int number_of_words, int *count);



