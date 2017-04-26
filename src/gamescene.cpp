#include "gamescene.hpp"
#include "scene.hpp"
#include "log.h"
#include <string>
#include "keyword.hpp"
#include "player.hpp"

using namespace engine;

Player *player1;
Player *player2;

bool GameScene::handlePlayer1(){
    int i=0,j=0,x=0,y=0;
    bool keyFlag = false;
    int mulpConst = -2;
    bool colliding = isColliding(player1, player2);
    //const Uint8* currentKeyStates = SDL_GetKeyboardState( NULL );
    if(Input::keyPressed(Input::UP))
    {
        x = 0;
        y = -3;
        i = 1;
        j = 3;
        keyFlag = true;
    }
    if(Input::keyPressed(Input::DOWN))
    {
        x = 0;
        y = 3;
        i = 1;
        j = 0;
        keyFlag = true;
    }
    if(Input::keyPressed(Input::RIGHT))
    {
        x = 3;
        y = 0;
        i = 1;
        j = 2;
        keyFlag = true;
    }
    if(Input::keyPressed(Input::LEFT))
    {
        x = -3;
        y = 0;
        i = 1;
        j = 1;
        keyFlag = true;
    }
    if(keyFlag){
        Vector2D pos(x,y);
        if(colliding) pos*=mulpConst;
        player1->update(pos,i,j);
    }
    return true;
}
bool GameScene::handlePlayer2(){
    int i,j,x=0,y=0;
    bool keyFlag = false;
    int mulpConst = -2;

    bool colliding = isColliding(player2,player1);
    //const Uint8* currentKeyStates = SDL_GetKeyboardState( NULL );
    if(Input::keyPressed(Input::W))
    {
        x = 0;
        y = -3;
        i = 1;
        j = 3;
        keyFlag = true;
    }
    if(Input::keyPressed(Input::S))
    {
        x = 0;
        y = 3;
        i = 1;
        j = 0;
        keyFlag = true;
    }
    if(Input::keyPressed(Input::D))
    {
        x = 3;
        y = 0;
        i = 1;
        j = 2;
        keyFlag = true;
    }
    if(Input::keyPressed(Input::A))
    {
        x = -3;
        y = 0;
        i = 1;
        j = 1;
        keyFlag = true;
    }
    if(keyFlag){
        Vector2D pos(x,y);
        if(colliding) pos*=mulpConst;
        player2->update(pos,i,j);
    }
    return true;
}


bool GameScene::update()
{
    player1 = (dynamic_cast<Player *>(m_objects["Player1"]));

    player2 = (dynamic_cast<Player *>(m_objects["Player2"]));

    handlePlayer1();
    
    handlePlayer2();

    return true;
}

bool GameScene::draw()
{
    Scene::draw();
    m_objects["Player1"]->draw();
    m_objects["Player2"]->draw();

    return true;
}