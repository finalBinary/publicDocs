/*  Gibt 1 zurück wenn das Produkt ausgegeben werden soll und 0 sonst.
    - haltbarkeit_allgemein ist das allgemeine Mindesthaltbarkeitsdatum
    - haltbarkeit_obst ist die Mindesthaltbarkeit von Obst
    - mindestanzahl entspricht dem Parameter zu -a (0 sonst)
    - umkehren ist 1 wenn die Aufgabenstellung umgedreht werden soll und 0 sonst
    - anzahl, kategorie und resthaltbarkeit die Werte des betrachteten Lebensmittels 
*/
int ausgeben(int haltbarkeit_allgemein, int haltbarkeit_obst, int mindestanzahl, int umkehren,
             int anzahl, char *kategorie, int resthaltbarkeit);

/* Gibt die (Mindest)haltbarkeit für ein bestimmtes Lebensmittel zurück. */
int individuelle_haltbarkeit(int haltbarkeit_allgemein, int haltbarkeit_obst, char *kategorie);
int ist_obst(char *kategorie);

/* Gibt 1 zurück wenn das Produkt oft genug vorhanden ist und 0 sonst. */
int ist_oft_genug_vorhanden(int mindestanzahl, int anzahl);



    
