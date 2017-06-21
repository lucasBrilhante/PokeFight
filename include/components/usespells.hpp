#ifndef __COMPONENTS_USE_SPELL__
#define __COMPONENTS_USE_SPELL__

#include "sdl2include.h"
#include "components/code.hpp"
#include "player.hpp"
#include "keyword.hpp"

using namespace engine;

class UseSpells : public CodeComponent {
public:
    UseSpells(Player & game_object,Input::keys _spell1,Input::keys _spell2,Input::keys _spell3)
        : CodeComponent(game_object), spell1(_spell1), spell2(_spell2), spell3(_spell3){}
        
    UseSpells() : CodeComponent() {}

    ~UseSpells() {}

    virtual bool update();
private:
	Input::keys spell1;
	Input::keys spell2;
	Input::keys spell3;
};



#endif