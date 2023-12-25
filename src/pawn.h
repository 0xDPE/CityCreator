#pragma once

#include <raylib.h>
#include "buildObject.h"

class Pawn 
{
public:
    bool debugLine;
    bool arrivedAtDest;
    bool isWondering;

    float x,y;
    float moveToX,moveToY;
    float speed;
    int rotation;

    Texture2D head;
    Texture2D hair;
    Texture2D eye;
    Texture2D body;
    Texture2D placeholder; 

    void draw();
    void wonder(int screenWidth, int screenHeight);
    void build();
    void move();

private:
      int counter = 0;
};