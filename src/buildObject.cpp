#include "buildObject.h"
#include "pawn.h"
#include <raylib.h>
#include <raymath.h>
#include <math.h>
#include <iostream>

void BuildObject::DrawHologram()
{
    Rectangle objectRectangle = {0,0,sprite.width,sprite.height};
    Rectangle spriteRec = {x,y, objectRectangle.width, objectRectangle.height};
    Vector2 objectCenter = {sprite.width/2, sprite.height/2};
    DrawTexturePro(sprite, objectRectangle, spriteRec, objectCenter,rotation, GREEN);
}

void BuildObject::Update()
{
    y = GetMouseY();
    x = GetMouseX();
    detectionCricle.center.x = x;
    detectionCricle.center.y = y;
}

bool BuildObject::inRadiusDetection(float pawnX, float pawnY)
{
    float centerToPoint = sqrt(pow((pawnX - detectionCricle.center.x), 2) + pow(pawnY - detectionCricle.center.y, 2));
    std::cout << centerToPoint << "\n";
    std::cout << detectionCricle.radius << "\n";
    if (centerToPoint < detectionCricle.radius)
    {
        return true;
    }
    else
    {
        return false;
    }
}