#include <raylib.h>
#include "buildObject.h"
#include "pawn.h"
#include <iostream>

int main()
{
 
    ChangeDirectory(GetApplicationDirectory());

    constexpr int screenWidth = 800;
    constexpr int screenHeight = 450;

    int display = GetCurrentMonitor();

    InitWindow(GetMonitorWidth(display), GetMonitorHeight(display), "City Creator");
    SetTargetFPS(60);
    bool isBorderless = true;


    Texture2D testSprite = LoadTexture("Asset/AngyBOB.png");
    BuildObject test;
    test.sprite = testSprite;
    test.rotation = 0;
    test.detectionCricle.radius = 20;

    Texture2D pawnSprite = LoadTexture("Asset/uncannyPawn.png");
    Pawn pawnTest;
    pawnTest.placeholder = pawnSprite; 
    pawnTest.x = GetMonitorWidth(display) / 2;
    pawnTest.y = GetMonitorHeight(display) / 2;
    pawnTest.debugLine = true;
    pawnTest.speed = 300;
    pawnTest.isWondering = false;


    while (!WindowShouldClose())
    {
        if(IsKeyPressed(KEY_ENTER) && (IsKeyDown(KEY_LEFT_ALT) || IsKeyDown(KEY_RIGHT_ALT)))
        {
            if (isBorderless)
            {
                SetWindowSize(screenWidth, screenHeight);
                isBorderless = false;
            }
            else
            {
                SetWindowSize(GetMonitorWidth(display), GetMonitorHeight(display));
                isBorderless = true;
            }
        }


        BeginDrawing();
        ClearBackground(WHITE);

        test.DrawHologram();
        pawnTest.draw();

        pawnTest.speed = 1;
        pawnTest.moveToX = test.x;
        pawnTest.moveToY = test.y;
        pawnTest.move();
        pawnTest.wonder(GetMonitorWidth(display), GetMonitorHeight(display));

        test.Update();
        //bool hasArrivedAtDest =  test.inRadiusDetection(pawnTest.x, pawnTest.y);
        //pawnTest.arrivedAtDest = hasArrivedAtDest;

        //std::cout << test.x << "\n";
        //std::cout << pawnTest.x << std::endl;

        EndDrawing();
    }

    CloseWindow();
    return 0;
}