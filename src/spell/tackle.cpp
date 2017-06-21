#include "gameobject.hpp"
#include "components/image.hpp"
#include "components/audio.hpp"
#include "log.h"
#include "vector.hpp"
#include "spell.hpp"
#include "timer.hpp"
#include "game.hpp"
#include "spell/tackle.hpp"
#include "player.hpp"


#define nframes 10

using namespace engine;

bool Tackle::init()
{
    Spell::init();
    setState(State::disabled);

    return true;
}

bool Tackle::shutdown()
{
    Spell::shutdown();
    return true;
}

bool Tackle::draw()
{
    Spell::draw();

    return true;
}

bool Tackle::update()
{
  if(durationTimer.getTime()< duration){
    //INFO("PLAYING");
    physics.collisionBox.x = player->physics.position.getX();
    physics.collisionBox.y = player->physics.position.getY();
    physics.collisionBox.w = player->w;
    physics.collisionBox.h = player->h;
    auto enemy = dynamic_cast<Player *>(player)->enemy;
    if(physics.detectCollision(enemy))
    {
        INFO("Hit enemy");
        Vector2D nulo(0,0);
        enemy->physics.velocity = nulo;
    
        auto hitVel = player->physics.velocity;
        hitVel.normalize();
        enemy->physics.velocity += (hitVel*(enemy->multiplier+1));
        enemy->multiplier += 0.2;
        //INFO(enemy->physics.position.getX() << "  " << enemy->physics.position.getY());
        setState(State::disabled);
        dynamic_cast<Player *>(player)->canMove = true;
        dynamic_cast<Player *>(player)->usingSpell = false;
    
        enemy->getHit(500, myUserDirection);
    }


  }else{
   	//quita do scene
   	INFO("Finish spell");
    setState(State::disabled);
    dynamic_cast<Player *>(player)->canMove = true;
    dynamic_cast<Player *>(player)->usingSpell = false;


   	//Game::instance.m_scene->remove_game_object(name());
  }
  Spell::update();

   return true;
}

bool Tackle::useSpell()
{
  if(countdownTimer.getTime() > countdown){
    INFO("Start spell");
    /*AudioComponent * audio = get_component<AudioComponent>();
    audio->play(1);*/
    setState(State::enabled);
    //sprite
    int defaultVel = 10;
    if(player->physics.direction == PhysicsComponent::Direction::up){
      int componentX = 0;
      int componentY = -1*defaultVel;

      Vector2D move(componentX,componentY);
      player->physics.velocity = move;

    }
    if(player->physics.direction == PhysicsComponent::Direction::down){
      int componentX = 0;
      int componentY = defaultVel;

      Vector2D move(componentX,componentY);
      player->physics.velocity = move;
    }
    if(player->physics.direction == PhysicsComponent::Direction::left){
      int componentX = -1*defaultVel;
      int componentY = 0;

      Vector2D move(componentX,componentY);
      player->physics.velocity = move;
    }
    if(player->physics.direction == PhysicsComponent::Direction::right){
      int componentX = defaultVel;
      int componentY = 0;

      Vector2D move(componentX,componentY);
      player->physics.velocity = move;
    }
    dynamic_cast<Player *>(player)->canMove = false;

  	durationTimer.startTimer();//sprite
    
    countdownTimer.startTimer();
    myUserDirection = dynamic_cast<Player *>(player)->physics.direction;
    dynamic_cast<Player *>(player)->usingSpell = true;

    //timer2.startTimer();
    setup();
  }else{
    INFO("on countdown");
  }
  return true;
}
void Tackle::setup()
{ 
  xF = 0;
  yF = 0;
  GameObject::setup();
}
