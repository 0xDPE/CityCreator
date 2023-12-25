#pragma once

#include "shapes.h"
#include "pawn.h"

#include <raylib.h>

class BuildObject
{
public: 
    float x,y;
    int rotation;
    Texture2D sprite;
    Circle detectionCricle; 

    void DrawHologram();
    void Update();
    bool inRadiusDetection(float pawnX, float pawnY);
};