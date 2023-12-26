#include <raylib.h>
#include <raymath.h>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <random>
#include "pawn.h"

void Pawn::draw()
{
    Rectangle pawnRect = {0,0,(float)placeholder.width,(float)placeholder.height};
    Rectangle destRect = {x,y,static_cast<float>(pawnRect.width*0.3), static_cast<float>(pawnRect.height*0.3)};
    Vector2 pawnOrigin = {static_cast<float>(placeholder.width/2 * 0.3), static_cast<float>(placeholder.height/2 * 0.3)};
    DrawTexturePro(placeholder, pawnRect,destRect, pawnOrigin, 0, WHITE);
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

void Pawn::wonder(int screenWidth, int screenHeight)
{
    if(!isWondering)
    {
        std::random_device rd;
        std::uniform_int_distribution<int> distX (1,screenWidth - 1);
        int numberX = distX(rd);
        std::uniform_int_distribution<int> distY (1,screenHeight - 1);
        int numberY = distY(rd);

        if (numberX <= 0)
        {
            numberX = 1;
        }else if (numberY <= 0 )
        {
            numberY = 1;
        }

        std::cout << numberX << "\n";
        std::cout << numberY << "\n";

        moveToX = numberX;
        moveToY = numberY;

        isWondering = true;
    }else
    {
        if (trunc(x) == moveToX || trunc(y) == moveToY)
        {
            isWondering = false;
        }
    }
}