#include "gameobject.hpp"
#include "pikachu.hpp"
#include "components/text.hpp"
#include "components/image.hpp"
#include "log.h"
#include "components/image.hpp"
#include "vector.hpp"



using namespace engine;

bool Pikachu::init()
{
    Player::init();

    return true;
}

bool Pikachu::shutdown()
{
    Player::shutdown();

    return true;
}

bool Pikachu::draw()
{
    Player::draw();

    return true;
}

bool Pikachu::update()
{
    Player::update();

    return true;
}
