#include <raylib.h>
#include <raymath.h>
#include <vector>
#include "collision_manager.h"
#include "level.h"
#include "body.h"

class LevelManager{
    std::vector<Level> levels;
    std::vector<Body*> l1bodies;
    CollisionManager *cm;
    std::vector<Body> b;
    Body bb;

    public:
    LevelManager(CollisionManager *cm){
        b.reserve(100);
        b.emplace_back();
        b.emplace_back(200,100,int(10),int(120),45.f,Vector2Zero());
        b.emplace_back(100,100,120,40,20.f,Vector2Zero());
        b.emplace_back(100,600,300,90,21.f,Vector2Zero());
        // for(int i= 0;i<b.size();i++){
        //     l1bodies.push_back(&b[i]);
        // }
        for(auto &bd : b){
            l1bodies.push_back(&bd);
        }
        Level l1(l1bodies);
        levels.push_back(l1);
        this->cm = cm;
    }
    void loadLevel(){
        for(int i = 0; i<levels.size();i++){
            for(int j = 0; j<levels[i].getBodies().size();j++){
                cm->add(levels[i].getBodies()[j]);
            }
        }
    }
    void drawLevel(){
        levels[0].DrawLevel();
    }
};