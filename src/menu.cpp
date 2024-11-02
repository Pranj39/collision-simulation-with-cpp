#pragma once
#include <raylib.h>
class MainMenu{
    public:
    MainMenu(){

        
    }
    void Draw(){
        DrawText("PRESS SPACE TO ENTER", GetScreenHeight()/2, GetScreenWidth()/4,50, RED);   
    }
};