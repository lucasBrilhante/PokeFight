#ifndef __GAMEOVER_SCENE__
#define __GAMEOVER_SCENE__

#include <string>
#include "scene.hpp"
#include "components/image.hpp"
#include "components/animation.hpp"

using namespace engine;

class GameOverScene : public Scene{
public:

    GameOverScene() : Scene("") {}
    GameOverScene(std::string _name)
        : Scene(_name) {}

    ~GameOverScene() {}
    bool update();
    bool draw();
    bool init();

    GameObject * p1;
    GameObject * p2;
    GameObject * win;
    GameObject * lose;
private:

};

#endif
