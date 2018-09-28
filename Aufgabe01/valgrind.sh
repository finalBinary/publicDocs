echo  "Prüfe guck..."
cp leeres_inventar.valgrind spielstand
2>&1 valgrind --log-file=guck.log ./guck > output.txt
echo "" >> output.txt
grep -qE "([^0]|[0-9]0) bytes in" guck.log &&  echo -e "\t... Speicherleck bei ./guck gefunden. Details in Datei guck.log." || echo -e "\t ...OK\n"



echo "Prüfe leeres Inventar"
cp leeres_inventar.valgrind spielstand
2>&1 valgrind --log-file=inv_leer.log ./inv >> output.txt
echo "" >> output.txt
grep -qE "([^0]|[0-9]0) bytes in" inv_leer.log &&  echo -e "\t... Speicherleck bei ./inv gefunden. Details in Datei inv_leer.log." || echo -e "\t ...OK\n"

echo "Prüfe volles Inventar"
cp volles_inventar.valgrind spielstand
2>&1 valgrind --log-file=inv_voll.log ./inv  >> output.txt
echo "" >> output.txt
grep -qE "([^0]|[0-9]0) bytes in" inv_voll.log &&  echo -e "\t... Speicherleck bei ./inv gefunden. Details in Datei inv_voll.log." || echo -e "\t ...OK\n"



echo "Prüfe nimm (Gegenstand nicht vorhanden)"
cp volles_inventar.valgrind spielstand
2>&1 valgrind --log-file=nimm_nichtDa.log ./nimm nichtDa >> output.txt
echo "" >> output.txt
grep -qE "([^0]|[0-9]0) bytes in" nimm_nichtDa.log &&  echo -e "\t... Speicherleck bei ./nimm gefunden. Details in Datei nimm_nichtDa.log." || echo -e "\t ...OK\n"

echo "Prüfe nimm (normal)"
cp volles_inventar.valgrind spielstand
2>&1 valgrind --log-file=nimm_meissel.log ./nimm Meissel >> output.txt
echo "" >> output.txt
grep -qE "([^0]|[0-9]0) bytes in" nimm_meissel.log &&  echo -e "\t... Speicherleck bei ./nimm gefunden. Details in Datei nimm_meissel.log." || echo -e "\t ...OK\n"

echo "Prüfe nimm (doppelt)"
cp volles_inventar.valgrind spielstand
2>&1 valgrind --log-file=nimm_hammer.log ./nimm Hammer >> output.txt
echo "" >> output.txt
grep -qE "([^0]|[0-9]0) bytes in" nimm_hammer.log &&  echo -e "\t... Speicherleck bei ./nimm gefunden. Details in Datei nimm_hammer.log." || echo -e "\t ...OK\n"

echo "ACHTUNG: Die Richtungen werden nicht einzeln getestet, wenn hier mehrere Funktionen verwendet werden, muss mehr getestet werden!"

echo "Prüfe gegen Wand laufen"
cp leeres_inventar.valgrind spielstand
2>&1 valgrind --log-file=laufe_wand.log ./s >> output.txt
echo "" >> output.txt
grep -qE "([^0]|[0-9]0) bytes in" laufe_wand.log &&  echo -e "\t... Speicherleck bei, laufen gefunden. Details in Datei laufe_wand.log." || echo -e "\t ...OK\n"

echo "Prüfe verschlossene Tuer"
cp valgrind/leeres_inventar spielstand
2>&1 valgrind --log-file=laufe_tuer_zu.log ./n >> output.txt
echo "" >> output.txt
grep -qE "([^0]|[0-9]0) bytes in" laufe_tuer_zu.log &&  echo -e "\t... Speicherleck bei, laufen gefunden. Details in Datei laufe_tuer_zu.log." || echo -e "\t ...OK\n"

echo "Prüfe verschlossene Tuer geht auf"
cp volles_inventar.valgrind spielstand
2>&1 valgrind --log-file=laufe_tuer_auf.log ./n >> output.txt
echo "" >> output.txt
grep -qE "([^0]|[0-9]0) bytes in" laufe_tuer_auf.log &&  echo -e "\t... Speicherleck bei, laufen gefunden. Details in Datei laufe_tuer_auf.log." || echo -e "\t ...OK\n"

echo "Prüfe offene Tuer"
cp offene_tuer.valgrind spielstand
2>&1 valgrind --log-file=laufe_offen.log ./w >> output.txt
echo "" >> output.txt
grep -qE "([^0]|[0-9]0) bytes in" laufe_offen.log &&  echo -e "\t... Speicherleck bei, laufen gefunden. Details in Datei laufe_offen.log." || echo -e "\t ...OK\n"

echo "Prüfe Freiheit"
cp offene_tuer.valgrind spielstand
2>&1 valgrind --log-file=laufe_freiheit.log ./n >> output.txt
echo "" >> output.txt
grep -qE "([^0]|[0-9]0) bytes in" laufe_freiheit.log &&  echo -e "\t... Speicherleck bei, laufen gefunden. Details in Datei laufe_freiheit.log." || echo -e "\t ...OK\n"


echo "Prüfe Spielstand nicht vorhanden"
rm spielstand
2>&1 valgrind --log-file=kein_spielstand.log ./guck >> output.txt
echo "" >> output.txt
grep -qE "([^0]|[0-9]0) bytes in" kein_spielstand.log &&  echo -e "\t... Speicherleck bei, laufen gefunden. Details in Datei kein_spielstand.log." || echo -e "\t ...OK\n"

echo "Prüfe Raum nicht vorhanden"
echo "KEINRAUM" >> spielstand
2>&1 valgrind --log-file=kein_raum.log.log ./n >> output.txt
echo "" >> output.txt
grep -qE "([^0]|[0-9]0) bytes in" kein_raum.log.log &&  echo -e "\t... Speicherleck bei, laufen gefunden. Details in Datei kein_raum.log." || echo -e "\t ...OK\n"

echo -e "\t Achtung: Rückgabewerte werden durch dieses Skript nicht geprüft!"
