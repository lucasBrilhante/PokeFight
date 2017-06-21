#ifndef __GAME_PLAYER_OBJECT__
#define __GAME_PLAYER_OBJECT__

#include <string>
#include <list>
#include <typeindex>
#include <typeinfo>
#include <unordered_map>
#include "vector.hpp"
#include "spell.hpp"
#include "gameobject.hpp"
#include "components/image.hpp"
#include "components/text.hpp"

using namespace engine;

class Player : public GameObject {
public:
    Player() : GameObject() {}
    Player(std::string _name,int _x,int _y)
        : GameObject(_name,_x,_y),positionX(_x),positionY(_y) {}

    ~Player() {}
    int life = 100;
    bool canMove = true;
    float multiplier = 1;
    int timeDisabled;
    bool usingSpell = false;

    virtual bool init();
    virtual bool shutdown();
    virtual bool update();
    virtual bool draw();

    void setEnemyPlayer(Player * _enemy){enemy = _enemy;}
    bool moveDown();
    bool moveUp();
    bool moveRight();
    bool moveLeft();
    void getHit(int time, PhysicsComponent::Direction direction);

    Timer disableTimer;
    Player * enemy;
    Spell * spell1;
    Spell * spell2;
    Spell * spell3;
    /*bool changeInstrument(std::string instrument);
    bool changeSprite(std::string sprite);
    
    void addInstrument(std::string instrument_name, Instrument instrument);
    void addSprite(std::string instrument_name, ImageComponent* sprite);
    Instrument getActiveInstrument();
    void addFragment(int _id);
    TextComponent* nFragments;
    void clearFragments();*/
    
private:
    bool handlePlayer();
    void shake();
    /*std::unordered_map<std::string, Instrument> instruments;
    std::unordered_map<std::string, ImageComponent*> sprites;
    Instrument active_instrument;
    ImageComponent* active_sprite;
    std::vector<int> fragments;*/
    int positionX;
    int positionY;
    int defaultVel = 5;
    bool shakeVel = 1;
    PhysicsComponent::Direction shakeDir = PhysicsComponent::Direction::none;
};

#endif
