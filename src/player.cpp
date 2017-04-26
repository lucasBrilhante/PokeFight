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

bool Player::update(Vector2D v,int xFInc,int yFSub)
{
    //engine::GameObject::update(force,xFInc,yFSub);
    velocity = v;
    velocity += aceleration;
    position += velocity;
    xF = xF+xFInc;
    yF = yFSub;

    return true;
}

