#pragma once
#include <raylib.h>
#include <raymath.h>
#include <vector>
#include "collision_manager.h"
#include "level.h"
#include "body.h"
#include "menu.cpp"
#include "lose_menu.h"
class LoseMenu;
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
    static int levelIndex;

    void initialize(std::vector<Body> &a, std::vector<Body*> &b);
    LevelManager();
    LevelManager(CollisionManager *cm);
    void loadLevel();
    void drawLevel();

    void endLevel();
};