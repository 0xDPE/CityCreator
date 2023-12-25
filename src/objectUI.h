#pragma once
#include <raygui.h>

class objectUI
{
public:
    float x,y;
    Texture2D Sprite;

    void draw();
    void buttonClicked();
};