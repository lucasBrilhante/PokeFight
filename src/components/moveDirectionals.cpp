#include "log.h"
#include "components/moveDirectionals.hpp"
#include "vector.hpp"
#include "game.hpp"
#include "tilemap.hpp"


bool MoveDirectionals::detectCollision(){
    bool keyFlag;
    auto map = Game::instance.m_scene->get_game_object("mapa");
    INFO("Colision detected");
    if((dynamic_cast<TileMap *>(map))->at(((m_game_object->physics.position.getX())/32),((m_game_object->physics.position.getY()+32)/32),2)==253)   
        keyFlag = false;   
    else{
        keyFlag = true;
    }
    return keyFlag;
}

bool MoveDirectionals::update(){

	bool keyFlag = false;

    if((dynamic_cast<Player *>(m_game_object))->canMove){
        if(Input::keyPressed(up))
        {
            m_game_object->physics.direction = PhysicsComponent::Direction::up;
            keyFlag = detectCollision();
            (dynamic_cast<Player *>(m_game_object))->moveUp();
        }
        if(Input::keyPressed(down))
        {
            m_game_object->physics.direction = PhysicsComponent::Direction::down;

            auto map = Game::instance.m_scene->get_game_object("mapa");
            if((dynamic_cast<TileMap *>(map))->at(((m_game_object->physics.position.getX()+20)/32),((m_game_object->physics.position.getY()+42)/32),2)==253)
               keyFlag = false;     
            else{
                keyFlag = true;
            }
            (dynamic_cast<Player *>(m_game_object))->moveDown();
        }
        if(Input::keyPressed(right))
        {
            m_game_object->physics.direction = PhysicsComponent::Direction::right;

            auto map = Game::instance.m_scene->get_game_object("mapa");
            if((dynamic_cast<TileMap *>(map))->at(((m_game_object->physics.position.getX()+20)/32),((m_game_object->physics.position.getY()+42)/32),2)==253)
               keyFlag = false;     
            else{
                keyFlag = true;
            }
            (dynamic_cast<Player *>(m_game_object))->moveRight();
        }
        if(Input::keyPressed(left))
        {
            m_game_object->physics.direction = PhysicsComponent::Direction::left;
            auto map = Game::instance.m_scene->get_game_object("mapa");
            if((dynamic_cast<TileMap *>(map))->at(((m_game_object->physics.position.getX())/32),((m_game_object->physics.position.getY()+42)/32),2)==253)
               keyFlag = false;     
            else{
                keyFlag = true;
            }
            (dynamic_cast<Player *>(m_game_object))->moveLeft();
        }

        if(!keyFlag){
            Vector2D nulo(0,0);
            m_game_object->physics.velocity = nulo;
        }
    }
	return true;
}