
#include "level_manager.h"
#include <IOSTREAM>
int LevelManager::levelIndex = -1;
    void LevelManager::initialize(std::vector<Body> &a, std::vector<Body*> &b){
        for(auto &bd : a){
            b.push_back(&bd);
        }
        Level l(b);
        levels.emplace_back(l);
    }
    LevelManager::LevelManager(){
        levelIndex = -1;
    }
    LevelManager::LevelManager(CollisionManager *cm){
        levelIndex = -1;
        b.reserve(100);
        b.emplace_back();
        b.emplace_back(200,100,int(10),int(120),45.f,Vector2Zero());
        b.emplace_back(100,100,120,40,20.f,Vector2Zero());
        b.emplace_back(100,350,300,90,21.f,Vector2Zero(),true);
        

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
    void LevelManager::loadLevel(){
        if(levelIndex>-1)
            {endLevel();
            for(int j = 0; j<levels[levelIndex].getBodies().size();j++){
                cm->add(levels[levelIndex].getBodies()[j]);
            }}
        if(levelIndex == -1){

        }
        
    }
    void LevelManager::drawLevel(){
        if(levelIndex == -1){
            MainMenu m;
            m.Draw();
            std::cout<<"LEVELINDEX";
        }
        else if(levelIndex == -2){

            LoseMenu l;
            l.Draw();
            l.Update();
        }else{
        levels[levelIndex].DrawLevel();
        }
    }

    void LevelManager::endLevel(){
        cm->clear();
    }