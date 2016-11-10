CC = g++
HEADS = game.h state.h map.h st_intro.h global.h
SRC = main.cc game.cc state.cc map.cc st_intro.cc
LDIR = .
LIBS = pdcurses
FLAGS = -L$(LDIR) -l$(LIBS)

hellfireRL.exe:  $(HEADS) $(SRC)
	$(CC) -o $@ $(SRC) $(FLAGS)
	
clean:
	rm *.o, diabloRL.exe -r -Force -ErrorAction SilentlyContinue
