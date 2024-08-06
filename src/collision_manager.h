#include <raylib.h>
#include <body.h>
#include <vector>
class CollisionManager{
    std::vector<Body*> bodies;
    public:
    bool checkCol(Body*, bool);
    void add(Body*);

};