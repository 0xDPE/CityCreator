#include <raylib.h>
#include <raymath.h>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include "pawn.h"

void Pawn::draw()
{
    Rectangle pawnRect = {0,0,(float)placeholder.width,(float)placeholder.height};
    Rectangle destRect = {x,y,static_cast<float>(pawnRect.width*0.3), static_cast<float>(pawnRect.height*0.3)};
    Vector2 pawnOrigin = {static_cast<float>(placeholder.width/2 * 0.3), static_cast<float>(placeholder.height/2 * 0.3)};
    DrawTexturePro(placeholder, pawnRect,destRect, pawnOrigin, 0, WHITE);
}

void Pawn::wonder(int screenWidth, int screenHeight) 
{
    if(!isWondering)
    {
        srand(time(NULL));

        int numberX = rand() % screenWidth;
    }
}

void Pawn::move()
{
    Vector2 startVec;
    startVec.x = x;
    startVec.y = y;
    Vector2 endVec;
    endVec.x = moveToX;
    endVec.y = moveToY;

    if (debugLine)
    {
        DrawLineV(startVec,endVec, RED);
    }

    Vector2 direction = Vector2Subtract(endVec, startVec);
    direction = Vector2Normalize(direction);

    x += direction.x * speed;
    y += direction.y * speed;

}