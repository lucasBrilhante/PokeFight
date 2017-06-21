#include "gameobject.hpp"
#include "components/image.hpp"
#include "components/audio.hpp"
#include "log.h"
#include "vector.hpp"
#include "spell.hpp"
#include "timer.hpp"
#include "game.hpp"
#include "spell/bulletseed.hpp"
#include "player.hpp"


#define nframes 10

using namespace engine;

bool BulletSeed::init()
{
    Spell::init();
    setState(State::disabled);

    return true;
}

bool BulletSeed::shutdown()
{
    Spell::shutdown();
    return true;
}

bool BulletSeed::draw()
{
    Spell::draw();

    return true;
}

bool BulletSeed::update()
{
  if(durationTimer.getTime()< duration){
    //INFO("PLAYING");
    int adjust = 20;
    physics.collisionBox.x = physics.position.getX()+adjust;
    physics.collisionBox.y = physics.position.getY()+adjust;
    physics.collisionBox.w = w - adjust;
    physics.collisionBox.h = h - adjust;
    auto enemy = dynamic_cast<Player *>(player)->enemy;
    if(physics.detectCollision(enemy))
    {
        INFO("Hit enemy");
        Vector2D nulo(0,0);
        enemy->physics.velocity = nulo;
    
        auto hitVel = physics.velocity;
        hitVel.normalize();
        enemy->physics.velocity += (hitVel*(enemy->multiplier+1));
        enemy->multiplier += 0.2;
        //INFO(enemy->physics.position.getX() << "  " << enemy->physics.position.getY());
        setState(State::disabled);
        enemy->getHit(500, myUserDirection);
    }

  }else{
   	//quita do scene
   	INFO("Finish spell");
    setState(State::disabled);

   	//Game::instance.m_scene->remove_game_object(name());
  }
  Spell::update();

   return true;
}

bool BulletSeed::useSpell()
{
  if(countdownTimer.getTime() > countdown){
    INFO("Start spell");
    /*AudioComponent * audio = get_component<AudioComponent>();
    audio->play(1);*/
    setState(State::enabled);
    physics.position = player->physics.position;
    physics.velocity = player->physics.velocity*5;
  	durationTimer.startTimer();
    countdownTimer.startTimer();
    myUserDirection = dynamic_cast<Player *>(player)->physics.direction;
    //timer2.startTimer();
    setup();
  }else{
    INFO("on countdown");
  }
  return true;
}
void BulletSeed::setup()
{
  xF = 0;
  yF = 0;
  GameObject::setup();
}
