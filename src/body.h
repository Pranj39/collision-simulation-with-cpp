
#pragma once
#include <raylib.h>
#include <rlgl.h>
#include <cmath>
#include <vector>
class Body{
    public:
    Body(){
        angle=32;
        
        x=200;
        speed={0,0};
        sizex=100;
        sizey=300;
        y=200;

    }
    Body(int x, int y, int sizex, int sizey, float angle, Vector2 speed):
    x(x), y(y), sizex(sizex), sizey(sizey), angle(angle){
        this->speed.x = speed.x;
        this->speed.y = speed.y;
    };
    Body(int x, int y, int sizex, int sizey, float angle, Vector2 speed, bool win):
    x(x), y(y), sizex(sizex), sizey(sizey), angle(angle), win(win){
        this->speed.x = speed.x;
        this->speed.y = speed.y;
    };

    Body(Body& b){
        this->x = b.x;
        this->y = b.y;
        this->angle = b.angle;
        this->speed = speed;
        this->angle = angle;
        this->sizex = sizex;
        this->sizey = sizey;
    }
    Body(Body&& b){
        this->x = b.x;
        this->y = b.y;
        this->angle = b.angle;
        this->speed = speed;
        this->angle = angle;
        this->sizex = sizex;
        this->sizey = sizey;
    }
    ~Body(){

    }
    virtual void Update(){
    }
    virtual void Draw(){
    rlPushMatrix();
    rlTranslatef(x+sizex/2,y+sizey/2,0);
    rlRotatef(angle,0,0,1);
    DrawRectangle(-sizex/2,-sizey/2,sizex,sizey,RED);
    rlPopMatrix();
    }
    virtual Vector2 getBounds(){
        return {float(sizex/2), float(sizey/2)};
    }
    virtual void Collide(Vector2 normal){

    }
    virtual Vector2 getPos(){
        
    Vector2 res;
    res.x = x+sizex/2;
    res.y = y+sizey/2;
    return res;
    }
    void setPos(Vector2 pos){
        x = pos.x;
        y = pos.y;
    }
    virtual Vector2 getSpeed(){
        return speed;
    }
    virtual void setSpeed(Vector2 s){
        speed.x = s.x;
        speed.y = s.y;
    }
    std::vector<Vector2> getAxis();
    virtual std::vector<Vector2> getCorners();
    std::vector<bool> project(Body*);
    Color col;
    float angle;
    
    bool win=false;
    protected:
    int x;
    Vector2 speed;
    int sizex;
    int sizey;
    int y;

};