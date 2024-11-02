#pragma once
#include <raylib.h>
#include <raymath.h>
#include <vector>
#include "collision_manager.h"
#include "level.h"
#include "body.h"
#include "menu.cpp"
class LevelManager{
    std::vector<Level> levels;
    std::vector<Body*> l1bodies;
    std::vector<Body*> l2bodies;
    std::vector<Body*> l3bodies;
    CollisionManager *cm;
    std::vector<Body> b;
    std::vector<Body> b2;
    std::vector<Body> b3;
    Body bb;

    public:
    int levelIndex=-1;

    void initialize(std::vector<Body> &a, std::vector<Body*> &b){
        for(auto &bd : a){
            b.push_back(&bd);
        }
        Level l(b);
        levels.emplace_back(l);
    }

    LevelManager(CollisionManager *cm){
        b.reserve(100);
        b.emplace_back();
        b.emplace_back(200,100,int(10),int(120),45.f,Vector2Zero());
        b.emplace_back(100,100,120,40,20.f,Vector2Zero());
        b.emplace_back(100,600,300,90,21.f,Vector2Zero(),true);
        

        b2.reserve(100);
        b2.emplace_back();
        b2.emplace_back(200,100,int(10),int(120),45.f,Vector2Zero(), true);

        b3.reserve(100);
        b3.emplace_back();
        // for(int i= 0;i<b.size();i++){
        //     l1bodies.push_back(&b[i]);
        // }
        initialize(b,l1bodies);
        initialize(b2,l2bodies);
        initialize(b3, l3bodies);
        this->cm = cm;
    }
    void loadLevel(int index){
        if(levelIndex>-1)
            {endLevel();
            for(int j = 0; j<levels[index].getBodies().size();j++){
                cm->add(levels[index].getBodies()[j]);
            }}
        
    }
    void drawLevel(int index){
        if(levelIndex == -1){
        }else{
        levels[index].DrawLevel();
        }
    }

    void endLevel(){
        cm->clear();
    }
};