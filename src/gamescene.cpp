#include "gamescene.hpp"
#include "scene.hpp"
#include "log.h"
#include <string>
#include "keyword.hpp"
#include "player.hpp"

using namespace engine;


bool GameScene::update()
{
    
    int mulpConst = -2;
	auto player1 = (dynamic_cast<Player *>(m_objects["Player1"]));
    bool col = verifyColision(player1);
    //const Uint8* currentKeyStates = SDL_GetKeyboardState( NULL );
    if(Input::keyPressed(Input::UP))
    {
        Vector2D vel(0,-3);
        if(col) vel*=mulpConst;
        player1->update(vel,1,3);
    }
    if(Input::keyPressed(Input::DOWN))
    {
        Vector2D vel(0,3);
        if(col) vel*=mulpConst;
        player1->update(vel,1,0);
    }
    if(Input::keyPressed(Input::RIGHT))
    {
        Vector2D vel(3,0);
        if(col) vel*=mulpConst;
        player1->update(vel,1,2);
    }
    if(Input::keyPressed(Input::LEFT))
    {
        Vector2D vel(-3,0);
        if(col) vel*=mulpConst;
        player1->update(vel,1,1);
    }

    
    auto player2 = (dynamic_cast<Player *>(m_objects["Player2"]));
    bool col2 = verifyColision(player2);
    //const Uint8* currentKeyStates = SDL_GetKeyboardState( NULL );
    if(Input::keyPressed(Input::W))
    {
        Vector2D vel(0,-3);
        if(col2) vel*=mulpConst;
        player2->update(vel,1,3);
    }
    if(Input::keyPressed(Input::S))
    {
        Vector2D vel(0,3);
        if(col2) vel*=mulpConst;
        player2->update(vel,1,0);
    }
    if(Input::keyPressed(Input::D))
    {
        Vector2D vel(3,0);
        if(col2) vel*=mulpConst;
        player2->update(vel,1,2);
    }
    if(Input::keyPressed(Input::A))
    {
        Vector2D vel(-3,0);
        if(col2) vel*=mulpConst;
        player2->update(vel,1,1);
    }

    return true;
}