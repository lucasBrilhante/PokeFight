#include "gameover.hpp"
#include "game.hpp"
#include "keyword.hpp"
#include "customimagecomponent.hpp"


using namespace engine;

bool GameOverScene::init(){
	Scene::init();
	
	int posX = 50;
	int winnerPosY = 100;
	int loserPosY = 300;

	if(Game::instance.p1Winner){
		auto image = p1->get_component<CustomImageComponent>();
		image->setWidth(80);
		image->setHeight(80);
		image->setX(posX);
		image->setY(winnerPosY);

		auto image2 = p2->get_component<CustomImageComponent>();
		image2->setWidth(80);
		image2->setHeight(80);
		image2->setX(posX);
		image2->setY(loserPosY);
	}else{
		auto image = p1->get_component<CustomImageComponent>();
		image->setWidth(80);
		image->setHeight(80);
		image->setX(posX);
		image->setY(loserPosY);

		auto image2 = p2->get_component<CustomImageComponent>();
		image2->setWidth(80);
		image2->setHeight(80);
		image2->setX(posX);
		image2->setY(winnerPosY);
	}
	return true;
}
bool GameOverScene::update()
{

    if(Input::keyPressed(Input::ESC))
    {
       engine::Game::instance.change_scene("Menu");
    }

    Scene::update();
    return true;
}
bool GameOverScene::draw(){
	Scene::draw();
	return true;
}

