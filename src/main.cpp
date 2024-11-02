#include <raylib.h>
#include <raymath.h>
#include "ball.h"
#include "body.h"
#include "level_manager.h"
#include "collision_manager.h" 
#include "menu.cpp"
#include <iostream>
int main()
{
    Color darkGreen = Color{20, 160, 133, 255};

    const int screenWidth = 1366;
    const int screenHeight = 768;
    int levelIndex=0;

    Ball ball;
    CollisionManager cm;
    LevelManager lm(&cm);
    cm.add(&ball);
    lm.loadLevel(levelIndex);
    InitWindow(screenWidth, screenHeight, "My first RAYLIB program!");
    SetTargetFPS(120);
    
    float time = GetTime();
    float deltaTime;
    bool prevCol = false;
    int i = 0;
    MainMenu *m = new MainMenu();
    while (!WindowShouldClose())
    {
        if (i<60)
        deltaTime = GetFrameTime();
        
        i++;

        if(IsKeyPressed(KEY_SPACE)){
            lm.levelIndex++;
            lm.endLevel();
            lm.loadLevel(lm.levelIndex);
        }
        BeginDrawing();
        ClearBackground(darkGreen);
        ball.Update(time, deltaTime);
        prevCol=cm.checkCol(&ball, prevCol, lm.levelIndex);
        
        if(lm.levelIndex<0){
            m->Draw();
        }else{
        ball.Draw();

        }
        lm.endLevel();
        lm.loadLevel(lm.levelIndex);
        lm.drawLevel(lm.levelIndex);
        Vector2 del = Vector2Subtract(ball.getPos(),GetMousePosition());
        del = Vector2Normalize(del);
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