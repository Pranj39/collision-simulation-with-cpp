#include <raylib.h>
#include <raymath.h>
#include <vector>
#include "collision_manager.h"
#include "level.h"
#include "body.h"

class LevelManager{
    std::vector<Level> levels;
    std::vector<Body*> l1bodies;
    std::vector<Body*> l2bodies;
    CollisionManager *cm;
    std::vector<Body> b;
    std::vector<Body> b2;
    Body bb;

    public:
    int levelIndex=0;

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
        b.emplace_back(100,600,300,90,21.f,Vector2Zero());

        b2.reserve(100);
        b2.emplace_back();
        b2.emplace_back(200,100,int(10),int(120),45.f,Vector2Zero());
        // for(int i= 0;i<b.size();i++){
        //     l1bodies.push_back(&b[i]);
        // }
        initialize(b,l1bodies);
        initialize(b2,l2bodies);
        this->cm = cm;
    }
    void loadLevel(int index){
            for(int j = 0; j<levels[index].getBodies().size();j++){
                cm->add(levels[index].getBodies()[j]);
            }
        
    }
    void drawLevel(int index){
        levels[index].DrawLevel();
    }

    void endLevel(){
        cm->clear();
    }
};