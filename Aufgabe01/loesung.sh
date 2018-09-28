echo "Wir versuchen automatisch zu entkommen..."
echo -e "###\n### TEIL 1 (Zelle): leeres Inventar, Raum anschauen, vergeblich versuchen den Raum zu verlassen" > ausgabe.txt
echo -e "###         Hammer aufnehmen, Inventar prüfen, Hammer erneut nehmen, Raum erfolgreich verlassen\n###" >> ausgabe.txt
echo "./inv" >> ausgabe.txt
./inv >> ausgabe.txt
echo "./guck" >> ausgabe.txt
./guck >> ausgabe.txt
echo "./n" >> ausgabe.txt
./n >> ausgabe.txt
echo "./nimm" >> ausgabe.txt
./nimm Hammer >> ausgabe.txt
echo "./nimm" >> ausgabe.txt
./nimm Hammer >> ausgabe.txt
echo "./inv" >> ausgabe.txt
./inv >> ausgabe.txt
echo "./n" >> ausgabe.txt
./n >> ausgabe.txt

echo -e "###\n### TEIL 2: Zellentrakt -> Duschen, Schwamm nicht nehmen können, Seife nehmen\n###" >> ausgabe.txt
echo "./o" >> ausgabe.txt
./o >>ausgabe.txt
echo "./n" >> ausgabe.txt
./n >>ausgabe.txt
echo "./nimm Schwamm" >> ausgabe.txt
./nimm Schwamm >> ausgabe.txt
echo "./nimm Seife" >> ausgabe.txt
./nimm Seife >>ausgabe.txt
echo "./s" >> ausgabe.txt
./s >>ausgabe.txt
	
echo -e "###\n### TEIL 3: Rundgang -> Mensa -> Wand, Nasemklemme nehmen \n###" >> ausgabe.txt
echo "./s" >> ausgabe.txt
./s >>ausgabe.txt
echo "./o" >> ausgabe.txt
./o >>ausgabe.txt
echo "./nimm Nasenklemme" >> ausgabe.txt
./nimm Nasenklemme >> ausgabe.txt
echo "./s" >> ausgabe.txt
./s >>ausgabe.txt

echo -e "###\n### TEIL 4: Küche->Abstellkammer Schlüssel holen, Küche \n###" >> ausgabe.txt
echo "./w" >> ausgabe.txt
./w >> ausgabe.txt
echo "./nimm Schluessel" >> ausgabe.txt
./nimm Schluessel >> ausgabe.txt
echo "./o" >> ausgabe.txt
./o >>ausgabe.txt
	
echo -e "###\n### TEIL 5:  Küche -> Mensa -> Rundgang -> Hof ->Abflsusrohr -> Freiheit\n###" >> ausgabe.txt
echo "./n" >> ausgabe.txt
./n >>ausgabe.txt
echo "./n" >> ausgabe.txt
./n >>ausgabe.txt
echo "./o" >> ausgabe.txt
./o >>ausgabe.txt
echo "./n" >> ausgabe.txt
./n >>ausgabe.txt
echo "./n" >> ausgabe.txt
./n >>ausgabe.txt
grep -q "Du bist in die rettende FREIHEIT entkommen und willst NIE wieder zurück." ausgabe.txt && echo -e "\tEntkommen! Super!" || echo -e "\t Leider nicht entkommen (oder die Erfoglsnachricht wurde nicht implementiert) :(" 

echo "Die Ausgaben dieses Durchlaufes finden Sie in der Datei ausgabe.txt"
