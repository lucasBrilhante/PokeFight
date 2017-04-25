#ifndef __GAME_BULBASAUR_OBJECT__
#define __GAME_BULBASAUR_OBJECT__

#include <string>
#include <list>
#include <typeindex>
#include <typeinfo>
#include <unordered_map>

#include "player.hpp"
#include "vector.hpp"


using namespace engine;

class Bulbasaur : public Player {
public:
    Bulbasaur() : Player() {}
    Bulbasaur(std::string _name,int _x,int _y)
        : Player(_name,_x,_y) {}
    //~Bulbasaur() {}

    ~Bulbasaur() {}

    bool init();
    bool shutdown();
    bool update(Vector2D v,int xFInc,int yFSub);
    bool draw();
    
private:
    
};



#endif
