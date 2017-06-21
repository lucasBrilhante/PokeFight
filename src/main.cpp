#include "game.hpp"
#include "gameobject.hpp"
#include "scene.hpp"
#include "components/image.hpp"
#include "components/text.hpp"
#include "components/audio.hpp"
#include "components/animation.hpp"
#include "components/moveDirectionals.hpp"
#include "components/usespells.hpp"
#include "spell/thundershock.hpp"
#include "spell/tackle.hpp"
#include "spell/bulletseed.hpp"
#include "keyword.hpp"
#include "customimagecomponent.hpp"
#include "player.hpp"
#include "gamescene.hpp"
#include "menuscene.hpp"
#include "gameover.hpp"
#include "spell.hpp"
#include "tilemap.hpp"
#include "tileset.hpp"
#include "log.h"
#include "gameglobals.hpp"

using namespace std;
using namespace engine;

int main(int, char**)
{
    // Configure game
    Game::instance.set_properties(globals::game_name, globals::window_size);

    // Setup scenes
    MenuScene menu("Menu");
    GameOverScene GameoverScene("Gameover");
    //MenuScene VictoryScene("Victory");
    GameScene room1("stage_1_room_1");
    
    /* Gamescene*/
    Game::instance.add_scene(menu);
    Game::instance.add_scene(room1);
    Game::instance.add_scene(GameoverScene);


    GameObject playbutton("playbutton",(globals::window_size.first/2)-50,(globals::window_size.second/2)-50);
    ImageComponent playImage(playbutton,"playbutton.png",1,1);
    playbutton.xF = 0; playbutton.yF = 0;
    playbutton.add_component(playImage);
    menu.add_game_object(playbutton);
    //Game::instance.add_scene(VictoryScene);
    /*-------------------------GameOver-----------------------------*/
    GameObject background("backgroundEnd",0,0);
    background.xF = 0; background.yF = 0;
    ImageComponent backgroundImage(background,"backgroundend.jpg",1,1);
    background.add_component(backgroundImage);

    GameObject pikaface("pikaface",0,0);
    pikaface.xF = 0; pikaface.yF = 40*3;
    CustomImageComponent pikafaceImage(pikaface,"faces.png",13,16);
    pikaface.add_component(pikafaceImage);

    GameObject bulbaface("bulbaface",0,0);
    bulbaface.xF = 0; bulbaface.yF = 0;
    CustomImageComponent bulbafaceImage(bulbaface,"faces.png",13,16);
    bulbaface.add_component(bulbafaceImage);



    GameoverScene.add_game_object(pikaface);
    GameoverScene.add_game_object(bulbaface);
    GameoverScene.add_game_object(background);

    GameoverScene.p1 = &pikaface;
    GameoverScene.p2 = &bulbaface;

    /*-------------------------player 1-----------------------------*/
    Player player(globals::player,100,100);
    player.xF = 0; player.yF = 0;
    //Components
    ImageComponent playerImage(player, "pikasheet.png", 4, 4);
    player.add_component(playerImage);

    MoveDirectionals move(player,Input::UP,Input::DOWN,Input::RIGHT,Input::LEFT);
    player.add_component(move);

    UseSpells spellsP1(player,Input::J,Input::K,Input::L);
    player.add_component(spellsP1);

    //Spells
    Thundershock p1Spell1("p1Spell1",&player,0,0,1000,1000);
    p1Spell1.xF = 0; p1Spell1.yF = 0; 
    player.spell1 = &p1Spell1;
    AnimationComponent thunder(p1Spell1, "thunder.png", 6, 6,1000,0,31);
    p1Spell1.add_component(thunder);
    room1.add_game_object(p1Spell1);

    //Spells
    Tackle p1Spell2("p1Spell2",&player,0,0,1000,200);
    player.spell2 = &p1Spell2;

    room1.add_game_object(player);
    room1.add_game_object(p1Spell2);

    GameObject lifePika("lifePika",5,40);
    TextComponent pikaText(lifePika,"0%","font.ttf",20);
    lifePika.add_component(pikaText);
    player.lifeText = &pikaText;

    room1.add_game_object(lifePika);



    /*-------------------------player 2-----------------------------*/
    Player player2(globals::player2,500,400);
    player2.xF = 0; player2.yF = 0;

    ImageComponent player2Image(player2, "bulbasheet.png", 4, 4);
    player2.add_component(player2Image);
    
    MoveDirectionals move2(player2,Input::W,Input::S,Input::D,Input::A);
    player2.add_component(move2);

    UseSpells spellsP2(player2,Input::F,Input::G,Input::H);
    player2.add_component(spellsP2);

    //Spells
    Thundershock p2Spell1("p2Spell1",&player2,0,0,1000,1000);
    p2Spell1.xF = 9; p2Spell1.yF = 0; 
    player2.spell1 = &p2Spell1;
    AnimationComponent seed(p2Spell1, "seed.png", 16, 16,1000,9,9);
    p2Spell1.add_component(seed);

    Tackle p2Spell2("p2Spell2",&player2,0,0,1000,200);
    player2.spell2 = &p2Spell2;

    room1.add_game_object(player2);
    room1.add_game_object(p2Spell2);    
    room1.add_game_object(p2Spell1);

    GameObject lifeBulba("lifeBulba",605,40);
    TextComponent bulbaText(lifeBulba,"0%","font.ttf",20);
    lifeBulba.add_component(bulbaText);
    player.lifeText = &bulbaText;
    
    room1.add_game_object(lifeBulba);


    /*--------------------------------------------------*/
    GameObject pikafaceHud("pikafaceHud",0,0);
    pikafaceHud.xF = 0; pikafaceHud.yF = 40*3;
    ImageComponent pikafaceHudImage(pikafaceHud,"faces.png",13,16);
    pikafaceHud.add_component(pikafaceHudImage);

    GameObject bulbafaceHud("bulbafaceHud",600,0);
    bulbafaceHud.xF = 0; bulbafaceHud.yF = 0;
    ImageComponent bulbafaceHudImage(bulbafaceHud,"faces.png",13,16);
    bulbafaceHud.add_component(bulbafaceHudImage);


    room1.add_game_object(pikafaceHud);
    room1.add_game_object(bulbafaceHud);
    // Other stuff
    player.setEnemyPlayer(&player2);
    player2.setEnemyPlayer(&player);

    TileMap tilemap("assets/mapa1.txt", "mapa", 0, 0);
    TileSet tileset(32, 32, tilemap, "tileset.png", 1, 1);
    tilemap.setTileSet(tileset);
    tilemap.add_component(tileset);

    room1.add_game_object(tilemap); 
    AudioComponent music(tilemap,"music.wav",true, true);
    tilemap.add_component(music);

/*    TileMap tilemap2("assets/mapa2.txt", "mapa", 0, 0); 
    TileSet tileset2(32, 32, tilemap2, "tilesheet.png", 1, 1);
    tilemap2.setTileSet(tileset2);
    tilemap2.add_component(tileset2);

    TileMap tilemap3("assets/mapa3.txt", "mapa", 0, 0); 
    TileSet tileset3(32, 32, tilemap3, "tilesheet.png", 1, 1);
    tilemap3.setTileSet(tileset3);
    tilemap3.add_component(tileset3);

    TileMap tilemap4("assets/mapa4.txt", "mapa", 0, 0); 
    TileSet tileset4(32, 32, tilemap4, "tilesheet.png", 1, 1);
    tilemap4.setTileSet(tileset4);
    tilemap4.add_component(tileset4);

    TileMap tilemap5("assets/mapa5.txt", "mapa", 0, 0); 
    TileSet tileset5(32, 32, tilemap5, "tilesheet.png", 1, 1);
    tilemap5.setTileSet(tileset5);
    tilemap5.add_component(tileset5);     


    HUDLife hudlife("hudlife", 0, 0, &player);
    hudlife.xF = 0; hudlife.yF = 0;
    ImageComponent lifeBar(hudlife, "hud_life.png", 1, 1);
    CustomImageComponent lifeBarContent(hudlife, "hud_life_full.png", 1, 1);
    hudlife.setLifeBar(&lifeBar);
    hudlife.setLifeBarContent(&lifeBarContent);
    hudlife.add_component(lifeBar);
    hudlife.add_component(lifeBarContent); 

    AudioComponent music(tilemap,"fase.mp3",true, true);
    tilemap.add_component(music);
    tilemap2.add_component(music);
    tilemap3.add_component(music);
    tilemap4.add_component(music);
    tilemap5.add_component(music);

    room1.add_game_object(tilemap); 
    room1.add_game_object(hudlife);
    room1.add_game_object(HUDInstrument);

    room2.add_game_object(hudlife);
    room2.add_game_object(HUDInstrument);
    room2.add_game_object(tilemap2);

    room3.add_game_object(hudlife);
    room3.add_game_object(HUDInstrument);
    room3.add_game_object(tilemap3);

    room4.add_game_object(hudlife);
    room4.add_game_object(HUDInstrument);
    room4.add_game_object(tilemap4);

    room5.add_game_object(hudlife);
    room5.add_game_object(HUDInstrument);
    room5.add_game_object(tilemap5);
*/

    // Game loop
    Game::instance.run();
    return 0;
}
