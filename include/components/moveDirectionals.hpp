#ifndef __COMPONENTS_MOVE__
#define __COMPONENTS_MOVE__

#include "sdl2include.h"
#include "components/code.hpp"
#include "player.hpp"
#include "keyword.hpp"

using namespace engine;

class MoveDirectionals : public CodeComponent {
public:
    MoveDirectionals(Player & game_object,Input::keys _up,Input::keys _down,Input::keys _right,Input::keys _left)
        : CodeComponent(game_object), up(_up), down(_down), right(_right), left(_left) {}
        
    MoveDirectionals() : CodeComponent() {}

    ~MoveDirectionals() {}

    virtual bool update();
private:
	bool detectCollision();
	Input::keys up;
	Input::keys down;
	Input::keys right;
	Input::keys left;
};



#endif
