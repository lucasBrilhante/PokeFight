#include "log.h"
#include "components/usespells.hpp"


bool UseSpells::update(){

    if(Input::keyPressed(spell1))
    {
        (dynamic_cast<Player *>(m_game_object))->spell1->useSpell();
    }
    if(Input::keyPressed(spell2))
    {
        (dynamic_cast<Player *>(m_game_object))->spell2->useSpell();
    }
    if(Input::keyPressed(spell3))
    {
        (dynamic_cast<Player *>(m_game_object))->spell3->useSpell();
    }
    
    return true;
}