#include "gamescene.hpp"
#include "scene.hpp"
#include "log.h"
#include <string>
#include "keyword.hpp"
#include "player.hpp"

using namespace engine;


bool GameScene::update()
{
	auto player = (dynamic_cast<Player *>(m_objects["Pikachu"]));
    //const Uint8* currentKeyStates = SDL_GetKeyboardState( NULL );
    if(Input::keyPressed(Input::UP))
    {
        player->update(0,-3,1,3);
    }
    if(Input::keyPressed(Input::DOWN))
    {
        player->update(0,3,1,0);
    }
    if(Input::keyPressed(Input::RIGHT))
    {
        player->update(3,0,1,2);
    }
    if(Input::keyPressed(Input::LEFT))
    {
        player->update(-3,0,1,1);
    }

    
    verifyColision(m_objects["Pikachu"]);

    return true;
}