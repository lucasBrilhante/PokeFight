#include "gamescene.hpp"
#include "scene.hpp"
#include "log.h"
#include <string>
#include "sdl2include.h"
#include "player.hpp"
using namespace engine;


bool GameScene::update()
{
	auto player = (dynamic_cast<Player *>(m_objects["Pikachu"]));
    const Uint8* currentKeyStates = SDL_GetKeyboardState( NULL );
    if(currentKeyStates != NULL){
        if(currentKeyStates[SDL_SCANCODE_UP])
        {
            player->update(0,-3,1,3);
        }
        if(currentKeyStates[SDL_SCANCODE_DOWN])
        {
            player->update(0,3,1,0);
        }
        if(currentKeyStates[SDL_SCANCODE_RIGHT])
        {
            player->update(3,0,1,2);
        }
        if(currentKeyStates[SDL_SCANCODE_LEFT])
        {
            player->update(-3,0,1,1);
        }

    }
    verifyColision(m_objects["Pikachu"]);

    return true;
}