#include "game.hpp"
#include "gameobject.hpp"
#include "scene.hpp"
#include "components/image.hpp"
#include "components/text.hpp"
#include "components/audio.hpp"
#include "player.hpp"
#include "gamescene.hpp"
#include "pikachu.hpp"
#include "bulbasaur.hpp"

#include "gameglobals.hpp"

using namespace engine;

int main(int, char**)
{
    // Configure game
    Game::instance.set_properties(globals::game_name, globals::window_size);

    // Setup scenes
    GameScene gameplay("Gameplay");
    Game::instance.add_scene(gameplay);

    //GameObject stone("pedra",300,300);
    //ImageComponent stoneImage(stone, "assets/sprites/tilesheet2.png",16,16);
    Pikachu pikachu("Player1",100,100);
    ImageComponent pikachuImage(pikachu, "assets/sprites/pikasheet.png",4,4);
    Bulbasaur bulbasaur("Player2",300,300);
    ImageComponent bulbasaurImage(bulbasaur, "assets/sprites/bulbasheet.png",4,4);
    //TextComponent text(pikachu, "Bem Vindo!", "assets/fonts/font.ttf", 42);
    //text.enable_high_quality();
    //AudioComponent pikachuAudio(pikachu,"assets/sprites/pika.wav")
    //stone.add_component(stoneImage);
    pikachu.add_component(pikachuImage);
    bulbasaur.add_component(bulbasaurImage);
    //pikachu.add_component(pikachuAudio);

    //pikachu.add_component(text);
    
    gameplay.add_game_object(pikachu);
    gameplay.add_game_object(bulbasaur);

    // Game loop
    Game::instance.run();

    return 0;
}
