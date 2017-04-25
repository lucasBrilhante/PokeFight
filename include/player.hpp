#ifndef __GAME_PLAYER_OBJECT__
#define __GAME_PLAYER_OBJECT__

#include <string>
#include <list>
#include <typeindex>
#include <typeinfo>
#include <unordered_map>
#include "vector.hpp"
#include "gameobject.hpp"

using namespace engine;

class Player : public GameObject {
public:
    Player() : GameObject() {}
    Player(std::string _name,int _x,int _y)
        : GameObject(_name,_x,_y) {}
    //~Player() {}

    ~Player() {}

    virtual bool init();
    virtual bool shutdown();
    virtual bool update(Vector2D force,int xFInc,int yFSub);
    virtual bool draw();

private:
    
};



#endif
