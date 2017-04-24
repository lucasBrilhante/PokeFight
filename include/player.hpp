#ifndef __ENGINE_PLAYER_OBJECT__
#define __ENGINE_PLAYER_OBJECT__

#include <string>
#include <list>
#include <typeindex>
#include <typeinfo>
#include <unordered_map>

#include "gameobject.hpp"

using namespace engine;

class Player : public GameObject {
public:
    enum class State {
            enabled,
            disabled,
            invalid
        };
    Player() : GameObject() {}
    Player(std::string _name,int _x,int _y)
        : GameObject(_name,_x,_y) {}
    //~Player() {}

    ~Player() {}

    bool init();
    bool shutdown();
    bool update(int xInc, int yInc,int xFInc,int yFSub);
    bool draw();
    
private:
    
};



#endif
