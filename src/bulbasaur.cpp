#include "gameobject.hpp"
#include "bulbasaur.hpp"
#include "components/text.hpp"
#include "components/image.hpp"
#include "log.h"
#include "vector.hpp"


using namespace engine;

bool Bulbasaur::init()
{
    Player::init();

    return true;
}

bool Bulbasaur::shutdown()
{
    Player::shutdown();

    return true;
}

bool Bulbasaur::draw()
{
    Player::draw();

    return true;
}

bool Bulbasaur::update(Vector2D v,int xFInc,int yFSub)
{
    Player::update(v,xFInc,yFSub);

    return true;
}
