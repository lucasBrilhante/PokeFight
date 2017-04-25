#include "gameobject.hpp"
#include "player.hpp"
#include "components/text.hpp"
#include "components/image.hpp"
#include "log.h"
#include "vector.hpp"

using namespace engine;

bool Player::init()
{
    engine::GameObject::init();
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

bool Player::update(Vector2D force,int xFInc,int yFSub)
{
	//m_currentFrame = int(((SDL_GetTicks() / 100) % 6));
	//velocity.setX(1);
	INFO("DESLOCAMENTO" << force.getX() << "   " << force.getY());
    engine::GameObject::update(force,xFInc,yFSub);
    return true;
}

