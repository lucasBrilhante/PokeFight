#include "gameobject.hpp"
#include "player.hpp"
#include "components/text.hpp"
#include "components/image.hpp"
#include "log.h"

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

bool Player::update(int xInc,int yInc,int xFInc,int yFSub)
{
    engine::GameObject::x = engine::GameObject::x+xInc;
    engine::GameObject::y = engine::GameObject::y+yInc;
    engine::GameObject::xF = engine::GameObject::xF+xFInc;
    engine::GameObject::yF = yFSub;
    return true;
}
