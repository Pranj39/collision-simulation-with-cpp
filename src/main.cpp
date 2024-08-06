#include <raylib.h>
#include <raymath.h>
#include "ball.h"
#include "body.h"
#include "collision_manager.h" 
#include <iostream>
int main()
{
    Color darkGreen = Color{20, 160, 133, 255};

    const int screenWidth = 800;
    const int screenHeight = 600;

    Ball ball;
    Body body;
    Body body2(100,100,40,40,25,{0,0});
    Body body3(50,100,40,100,135,{0,0});

    CollisionManager cm;
    cm.add(&ball);
    cm.add(&body);
    cm.add(&body2);
    cm.add(&body3);
    InitWindow(screenWidth, screenHeight, "My first RAYLIB program!");
    SetTargetFPS(120);
    
    float time = GetTime();
    float deltaTime;
    bool prevCol = false;
    int i = 0;
    while (!WindowShouldClose())
    {
        if (i<60)
        deltaTime = GetFrameTime();
        
        i++;
        BeginDrawing();
        ClearBackground(darkGreen);
        ball.Update(time, deltaTime);
        prevCol=cm.checkCol(&ball, prevCol);
        ball.Draw();
        body.Draw();
        body2.Draw();
        body3.Draw();
        Vector2 del = ball.getPos().Add(GetMousePosition().Multiply(-1));
        del = del.Normalize();
        if(IsMouseButtonDown(0)){
            ball.setSpeed({0,0});
            DrawLine(GetMousePosition().x, GetMousePosition().y, GetMousePosition().x + del.x*350, GetMousePosition().y+del.y*350, MAGENTA);
        }
        if(IsMouseButtonReleased(0)){
            ball.setSpeed({del.x*1000,del.y*1000});
    
        }

        EndDrawing();
    }

    CloseWindow();
    return 0;
}