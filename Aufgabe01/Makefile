all: dungeon.c dungeon.h
	gcc dungeon.c -Wall -std=c99 -g 
	@cp ./a.out n
	@cp ./a.out s
	@cp ./a.out o
	@cp ./a.out w
	@cp ./a.out guck
	@cp ./a.out inv
	@cp ./a.out nimm

clean:
	#todo: entfernen Sie die erstellten Programme, sowie alle log files

neustart: all
	@echo "Sicherheitskopie erstellen..."
	-@mv spielstand spielstand.bak && echo "...done"
	@echo "Spielstand zurücksetzen..."
	@cp spielstand.neustart spielstand && echo "...done"
	@chmod u+w spielstand 

valgrind: all valgrind.sh
	sh valgrind.sh

loesung: neustart loesung.sh
	@sh loesung.sh

	@echo -e "###\n### Zusatzprüfung (muss nicht implementiert werden):  Was passiert wenn wir entkommen sind? \n###" >> ausgabe.txt
	./guck 

