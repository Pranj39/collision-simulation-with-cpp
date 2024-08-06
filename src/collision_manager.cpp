#include "collision_manager.h"
#include <iostream>
#include <cmath>
bool CollisionManager::checkCol(Body *b1, bool prevCol){
    for(auto b : bodies){
        if(b1!=b){
            std::vector<bool> a = b1->project(b);
            std::vector<bool> m = b->project(b1);
            if(a.at(0)&&a.at(1)&&m.at(0)&&m.at(1)){
                b1->col= RED;
                DrawText("COOIDING",0,0,100,BLACK);
                Vector2 faces[4] ={
                    {1,0},{-1,0},{0,-1},{0,1}
                };
                for(int i =0;i<4;i++){
                    faces[i] = faces[i].Rotate(b->angle*3.14/180);
                }
                Vector2 normal;

                float distances[4] = {
                    (b->getCorners()[0].Add(b->getPos().Multiply(-1))).Angle(b->getAxis()[0]),
                    (b->getCorners()[1].Add(b->getPos().Multiply(-1))).Angle(b->getAxis()[0]),
                    (b->getCorners()[2].Add(b->getPos().Multiply(-1))).Angle(b->getAxis()[0]),
                    (b->getCorners()[3].Add(b->getPos().Multiply(-1))).Angle(b->getAxis()[0]),
                    // std::abs(b1->getPos().x-(b1->getAxis()[0].Multiply(b1->getBounds().x)).x-b->getPos().x-(b->getAxis()[0].Multiply(b->getBounds().x)).x),
                    // std::abs(b1->getPos().x+(b1->getAxis()[0].Multiply(b1->getBounds().x)).x-b->getPos().x+(b->getAxis()[0].Multiply(b->getBounds().x)).x),
                    // std::abs(b1->getPos().y-(b1->getAxis()[1].Multiply(b1->getBounds().y)).y-b->getPos().y-(b->getAxis()[1].Multiply(b->getBounds().y)).y),
                    // std::abs(b1->getPos().y+(b1->getAxis()[1].Multiply(b1->getBounds().y)).y-b->getPos().y+(b1->getAxis()[1].Multiply(b1->getBounds().y)).y)
                };
                float pen=(b1->getPos().Add(b->getPos().Multiply(-1))).Angle(b->getAxis()[0]);
                float d = (faces[2].x*(b1->getPos().Add(b->getPos().Multiply(-1))).x+faces[2].y*(b1->getPos().Add(b->getPos().Multiply(-1))).y);
                if(d>0)
                pen *= 1;
                else
                pen *= -1;
                for(int i=0;i<4;i++){
                    Vector2 cor = (b->getCorners()[i].Add(b->getPos().Multiply(-1)));
                    float dot = cor.x*faces[2].x+cor.y*faces[2].y;
                    if(dot>0)
                    distances[i] *= 1;
                    else{
                        distances[i] *=-1;
                    }
                }

                if(pen>=distances[0]&&pen<=distances[1]){
                    normal = faces[0];
                }else if(pen<=distances[2]&&pen>=distances[1]){
                    normal = faces[2];
                }else if(pen>=distances[2]||pen<=distances[3]){
                    normal = faces[1];
                }else if(pen<=distances[0]&&pen>=distances[3]){
                    normal = faces[3];
                }
                std::cout<<pen*180/3.14;
                // for(int i=0;i<4;i++){
                //     if(distances[i]<pen){
                //         pen = distances[i];
                //         normal = faces[i];
                //     }
                // }
                // std::cout<<normal.x<<","<<normal.y;
                if(!prevCol){
                    b1->Collide(normal);
                    prevCol = true;
                }else{
                    b1->setPos(b1->getPos().Add(normal.Multiply(2)));
                    b1->setSpeed(normal.Multiply(b1->getSpeed().Magnitude()));
                    prevCol = true;
                }
                return prevCol;
                }
        }else{
            b1->col = BLACK;
        }
    }
    return false;
}

void CollisionManager::add(Body *b){
    bodies.push_back(b); 
}