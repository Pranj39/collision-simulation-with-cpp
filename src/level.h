#pragma once
#include <raylib.h>
#include <raymath.h>
#include <vector>
#include <body.h>
#include "collision_manager.h"

class Level{
    std::vector<Body*> bodies;
    CollisionManager cm;
    public:
    Level(Body *b){
        bodies.emplace_back(b);
    }
    Level(){}

    Level(Level& l){
        bodies = l.bodies;
    }
    
    Level(Level&& l){
        bodies = l.bodies;
    }
    ~Level(){}

    Level(std::vector<Body*> bodies){
        for(int i =0;i<bodies.size();i++){
            this->bodies.emplace_back(bodies[i]);
        }
    }

    void DrawLevel(){
        for(int i = 0; i<bodies.size();i++){
            bodies[i]->Draw();
        }
    }
    std::vector<Body*> getBodies(){
        return bodies;
    }
};