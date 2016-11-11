#ifndef ST_INPLAY_H
#define ST_INPLAY_H

#include "game.h"
#include "global.h"
#include "map.h"
#include <vector>

struct InPlay : State
{

    InPlay(Game* game);
    void update();
    void draw();

    int display[SCREEN_HEIGHT][SCREEN_WIDTH];
    std::vector<Map*> maps;
};

#endif
