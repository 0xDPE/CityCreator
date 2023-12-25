#include <raylib.h>
#include <raymath.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include "pawn.h"

void Pawn::draw()
{
    Rectangle pawnRect = {0,0,placeholder.width,placeholder.height};
    Rectangle destRect = {x,y,pawnRect.width*0.3, pawnRect.height*0.3};
    Vector2 pawnOrigin = {placeholder.width/2 * 0.3, placeholder.height/2 * 0.3};
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