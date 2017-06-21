#include "gameobject.hpp"
#include "player.hpp"
#include "components/text.hpp"
#include "components/image.hpp"
#include "log.h"
#include "vector.hpp"
#include "keyword.hpp"
#include "gameglobals.hpp"
#include <sstream>
#include "game.hpp"


#define nframes 4

using namespace engine;

bool Player::init()
{
    engine::GameObject::init();
    physics.position.setX(positionX);
    physics.position.setY(positionY);
/*
    for(auto instrument : instruments){
        instrument.second.init();
    }

    active_instrument = instruments[globals::banjo];
    active_sprite = sprites[globals::banjo];

    sprites[globals::eletric_guitar]->setState(Component::State::disabled);
    sprites[globals::accordion]->setState(Component::State::disabled);*/

    //INFO("x"<<physics.collisionBox.x<<"  y"<<physics.collisionBox.y <<"  w"<<physics.collisionBox.w<< "    h"<< physics.collisionBox.h)
    return true;
}

bool Player::shutdown()
{
    engine::GameObject::shutdown();
    return true;
}

bool Player::draw()
{
    engine::GameObject::draw();
    return true;
}

bool Player::update()
{
    //handlePlayer();

    GameObject::update();
    
    int collisionAdjust = 30;
    physics.collisionBox.x = physics.position.getX() + collisionAdjust;
    physics.collisionBox.y = physics.position.getY() + collisionAdjust;
    physics.collisionBox.w = w - collisionAdjust;
    physics.collisionBox.h = h - collisionAdjust;
    if(!canMove){
        if(disableTimer.getTime() < timeDisabled) {
            shake();
            //INFO("aaaa" << physics.velocity.getX() << "  " << physics.velocity.getY());
        }else if(usingSpell){

        }
        else{
            canMove = true;
        }
        
    }
    if(physics.position.getX() < 0 || physics.position.getY() < 10 ||
    physics.position.getY() > 515 || physics.position.getX() > 570){
        Game::instance.change_scene("Gameover");
    }
    return true;
}
bool Player::moveDown(){
    // Update Velocity
    int componentX = 0;
    int componentY = defaultVel;

    Vector2D move(componentX,componentY);
    physics.velocity = move;
    // Update Frame
    int xFrame = (((xF/w)+1)%nframes)*w;
    int yFrame = 0*h;

    xF = xFrame;
    yF = yFrame;
    return true;
}

bool Player::moveUp(){
    // Update Velocity
    int componentX = 0;
    int componentY = -1*defaultVel;

    Vector2D move(componentX,componentY);
    physics.velocity = move;
    // Update Frame
    int xFrame = (((xF/w)+1)%nframes)*w;
    int yFrame = 3*h;

    xF = xFrame;
    yF = yFrame;
    return true;
}

bool Player::moveLeft(){
    // Update Velocity
    int componentX = -1*defaultVel;

    int componentY = 0;

    Vector2D move(componentX,componentY);
    physics.velocity = move;
    // Update Frame
    int xFrame = (((xF/w)+1)%nframes)*w;
    int yFrame = 1*h;

    xF = xFrame;
    yF = yFrame;
    return true;
}

bool Player::moveRight(){
    // Update Velocity

    int componentX = defaultVel;
    int componentY = 0;

    Vector2D move(componentX,componentY);
    physics.velocity = move;
    // Update Frame
    int xFrame = (((xF/w)+1)%nframes)*w;
    int yFrame = 2*h;

    xF = xFrame;
    yF = yFrame;
    return true;
}
void Player::getHit(int timeSpell,PhysicsComponent::Direction direction){
    disableTimer.startTimer();
    timeDisabled = timeSpell;
    canMove = false;
    shakeDir = direction;
    
    //sprite
    if(direction == PhysicsComponent::Direction::up){
        xF = 0*w;
        yF = 0*h;
        physics.velocity.m_x = shakeVel;
    }
    if(direction == PhysicsComponent::Direction::down){
        xF = 0*w;
        yF = 3*h;
        physics.velocity.m_x= shakeVel;
    }
    if(direction == PhysicsComponent::Direction::left){
        xF = 0*w;
        yF = 2*h;
        physics.velocity.m_y = shakeVel;
    }
    if(direction == PhysicsComponent::Direction::right){
        xF = 0*w;
        yF = 1*h;
        physics.velocity.m_y = shakeVel;
    }

}
void Player::shake(){
    if(shakeDir == PhysicsComponent::Direction::up || shakeDir == PhysicsComponent::Direction::down){
        physics.velocity.m_x *=-1;
    }
    if(shakeDir == PhysicsComponent::Direction::right || shakeDir == PhysicsComponent::Direction::left){
        physics.velocity.m_y *=-1;
    }
}

/*bool Player::changeInstrument(std::string instrument_name){
    INFO("Changing Instrument to " << instrument_name);
    Instrument instrument = instruments[instrument_name];
    bool isInstrumentNull = true;

    active_instrument = instrument;
    changeSprite(instrument_name);

    return isInstrumentNull;
}

bool Player::changeSprite(std::string sprite_name){
    INFO("Changing Sprite to " << sprite_name);
    ImageComponent* sprite = sprites[sprite_name];
   
    active_sprite->setState(Component::State::disabled);
    sprite->setState(Component::State::enabled);
    active_sprite = sprite;

    return true;
}

bool Player::handlePlayer(){
    
    if(Input::keyPressed(Input::Q))
    {
        spellQ->useSpell();
    }
    if(Input::keyPressed(Input::W))
    {
        spellW->useSpell();
    }
    if(Input::keyPressed(Input::E))
    {
        spellE->useSpell();
    }
    
    return true;
}*/
/*
void Player::addInstrument(std::string instrument_name, Instrument instrument){
    instruments[instrument_name] = instrument;
}

void Player::addSprite(std::string instrument_name, ImageComponent * sprite){
    sprites[instrument_name] = sprite;
}

Instrument Player::getActiveInstrument(){
    return active_instrument;
}

void Player::addFragment(int _id){
    fragments.push_back(_id);
    if(fragments.size() == 4) {
        engine::Game::instance.change_scene("Victory");
        physics.position.setX(getInitialX());
        physics.position.setY(getInitialY());
        life = 100;

    }

    std::stringstream ss;
    ss << "Numero de fragmentos: "<<fragments.size();
    

    nFragments->setText(ss.str());
    nFragments->init();
}
void Player::clearFragments(){
    fragments.clear();

    std::stringstream ss;
    ss << "Numero de fragmentos: "<<fragments.size();

    nFragments->setText(ss.str());
    nFragments->init();


}*/
