CC = g++
HEADS = game.h state.h map.h st_intro.h st_menu.h st_inplay.h entity.h component.h comp_position.h comp_tile.h comp_playerControllable.h assemblages.h global.h
SRC = main.cc game.cc state.cc map.cc st_intro.cc st_menu.cc st_inplay.cc
LDIR = .
LIBS = pdcurses
FLAGS = -L$(LDIR) -l$(LIBS)

hellfireRL.exe:  $(HEADS) $(SRC)
	$(CC) -o $@ $(SRC) $(FLAGS)

clean:
	rm *.o, diabloRL.exe -r -Force -ErrorAction SilentlyContinue
