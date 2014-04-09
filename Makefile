OBJECTS = main.o wczytywanie.o wypisywanie.o automat_komorkowy.o
HEADERS = headers
SRC = src
CFLAGS = -Wall -ansi -pedantic

main.o wczytywanie.o : $(HEADERS)/wczytywanie.h
main.o automat_komorkowy.o : $(HEADERS)/automat_komorkowy.h
main.o wczytywanie.o automat_komorkowy.o wypisywanie.o: $(HEADERS)/wypisywanie.h


all: $(OBJECTS)
	@echo "Lacze moduly *.o"
	@gcc $(CFLAGS) -oprogram $^

main.o: $(SRC)/main.c
	@echo "Kompiluje modul $@"
	@gcc -c $(CFLAGS) -I$(HEADERS) $^

automat_komorkowy.o: $(SRC)/automat_komorkowy.c
	@echo "Kompiluje modul $@"
	@gcc -c $(CFLAGS) -I$(HEADERS) $^

wypisywanie.o: $(SRC)/wypisywanie.c
	@echo "Kompiluje modul $@"
	@gcc -c $(CFLAGS) -I$(HEADERS) $^

wczytywanie.o: $(SRC)/wczytywanie.c
	@echo "Kompiluje modul $@"
	@gcc -c $(CFLAGS) -I$(HEADERS) $^

test:
	./program altstart 5

clean:
	rm *.o
