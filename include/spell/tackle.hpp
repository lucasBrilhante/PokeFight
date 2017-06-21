#ifndef __TACKLE__
#define __TACKLE__

#include <string>
#include <list>
#include <typeindex>
#include <typeinfo>
#include <unordered_map>
#include "vector.hpp"
#include "gameobject.hpp"
#include "timer.hpp"
#include "spell.hpp"

using namespace engine;
    
class Tackle : public Spell {
public:
    Tackle() : Spell() {}
    Tackle(std::string _name, GameObject * obj, int _x, int _y,int _countdown,int _duration)
        : Spell(_name,obj,_x,_y,_countdown,_duration) {}

    ~Tackle() {}
    
    bool init();
    bool shutdown();
    bool update();
    bool draw();
    bool useSpell();
    void setup();
    
    PhysicsComponent::Direction myUserDirection;
};

#endif