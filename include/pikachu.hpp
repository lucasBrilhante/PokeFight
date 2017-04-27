#ifndef __GAME_PIKACHU_OBJECT__
#define __GAME_PIKACHU_OBJECT__

#include <string>
#include <list>
#include <typeindex>
#include <typeinfo>
#include <unordered_map>

#include "player.hpp"
#include "vector.hpp"


using namespace engine;

class Pikachu : public Player {
public:
    Pikachu() : Player() {}
    Pikachu(std::string _name,int _x,int _y)
        : Player(_name,_x,_y) {}
    //~Pikachu() {}

    ~Pikachu() {}

    bool init();
    bool shutdown();
    bool update();
    bool draw();
    
private:
    
};



#endif
