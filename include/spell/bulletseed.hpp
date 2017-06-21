#ifndef __BULLETSEED__
#define __BULLETSEED__

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
    
class BulletSeed : public Spell {
public:
    BulletSeed() : Spell() {}
    BulletSeed(std::string _name, GameObject * obj, int _x, int _y,int _countdown,int _duration)
        : Spell(_name,obj,_x,_y,_countdown,_duration) {}

    ~BulletSeed() {}
    
    bool init();
    bool shutdown();
    bool update();
    bool draw();
    bool useSpell();
    void setup();
    
    PhysicsComponent::Direction myUserDirection;
};

#endif