#include "game.hpp"
#include "gameobject.hpp"
#include "scene.hpp"
#include "components/image.hpp"
#include "components/text.hpp"
#include "components/audio.hpp"
#include "player.hpp"
#include "gamescene.hpp"
#include "menuscene.hpp"
#include "pikachu.hpp"
#include "bulbasaur.hpp"

#include "gameglobals.hpp"
using namespace std;
using namespace engine;


int main(int, char**)
{
    // Configure game
    Game::instance.set_properties(globals::game_name, globals::window_size);

    // Setup scenes
    GameScene gameplay("Gameplay");
    MenuScene menu("Menu");
    /* Menu*/
    Game::instance.add_scene(menu);
    
    GameObject playbutton("playbutton",200,200);
    ImageComponent playImage(playbutton,"assets/sprites/playbutton.png",1,1);
    playbutton.add_component(playImage);
    menu.add_game_object(playbutton);


    /* Gamescene*/
    Game::instance.add_scene(gameplay);

    Pikachu pikachu("Player1",100,100);
    pikachu.xF = 0; pikachu.yF = 0;
    ImageComponent pikachuImage(pikachu, "assets/sprites/pikasheet.png",4,4);
    Bulbasaur bulbasaur("Player2",300,300);
    bulbasaur.xF = 0; bulbasaur.yF = 0;
    ImageComponent bulbasaurImage(bulbasaur, "assets/sprites/bulbasheet.png",4,4);
    
    pikachu.add_component(pikachuImage);
    bulbasaur.add_component(bulbasaurImage);

    gameplay.add_game_object(pikachu);
    gameplay.add_game_object(bulbasaur);


    GameObject field("field",0,0);
    field.xF = 0;field.yF = 0;
    ImageComponent f(field,"assets/sprites/tilesheet.png",8,8);
    field.add_component(f);
    gameplay.add_game_object(field);
    
    GameObject field1("field1",64,0);
    field1.xF = 1;field1.yF = 0;
    ImageComponent f1(field1,"assets/sprites/tilesheet.png",8,8);
    field1.add_component(f1);
    gameplay.add_game_object(field1);
    
    GameObject field2("field2",0,64);
    field2.xF = 0;field2.yF = 1;
    ImageComponent f2(field2,"assets/sprites/tilesheet.png",8,8);
    field2.add_component(f2);
    gameplay.add_game_object(field2);

    GameObject field3("field3",64,64);
    field3.xF = 1;field3.yF = 1;
    ImageComponent f3(field3,"assets/sprites/tilesheet.png",8,8);
    field3.add_component(f3);
    gameplay.add_game_object(field3);

    GameObject field4("field4",64,64);
    field4.xF = 1;field4.yF = 1;
    ImageComponent f4(field4,"assets/sprites/tilesheet.png",8,8);
    field4.add_component(f4);
    gameplay.add_game_object(field4);

    GameObject field5("field5",128,64);
    field5.xF = 1;field5.yF = 1;
    ImageComponent f5(field5,"assets/sprites/tilesheet.png",8,8);
    field5.add_component(f5);
    gameplay.add_game_object(field5);

    GameObject field6("field6",64,128);
    field6.xF = 1;field6.yF = 1;
    ImageComponent f6(field6,"assets/sprites/tilesheet.png",8,8);
    field6.add_component(f6);
    gameplay.add_game_object(field6);

    GameObject field7("field7",128,128);
    field7.xF = 1;field7.yF = 1;
    ImageComponent f7(field7,"assets/sprites/tilesheet.png",8,8);
    field7.add_component(f7);
    gameplay.add_game_object(field7);

    GameObject field8("field8",192,64);
    field8.xF = 1;field8.yF = 1;
    ImageComponent f8(field8,"assets/sprites/tilesheet.png",8,8);
    field8.add_component(f8);
    gameplay.add_game_object(field8);

    GameObject field9("field9",64,192);
    field9.xF = 1;field9.yF = 1;
    ImageComponent f9(field9,"assets/sprites/tilesheet.png",8,8);
    field9.add_component(f9);
    gameplay.add_game_object(field9);

    GameObject field10("field10",192,128);
    field10.xF = 1;field10.yF = 1;
    ImageComponent f10(field10,"assets/sprites/tilesheet.png",8,8);
    field10.add_component(f10);
    gameplay.add_game_object(field10);

    GameObject field11("field11",128,192);
    field11.xF = 1;field11.yF = 1;
    ImageComponent f11(field11,"assets/sprites/tilesheet.png",8,8);
    field11.add_component(f11);
    gameplay.add_game_object(field11);

    GameObject field12("field12",192,192);
    field12.xF = 1;field12.yF = 1;
    ImageComponent f12(field12,"assets/sprites/tilesheet.png",8,8);
    field12.add_component(f12);
    gameplay.add_game_object(field12);

    GameObject field13("field13",256,64);
    field13.xF = 1;field13.yF = 1;
    ImageComponent f13(field13,"assets/sprites/tilesheet.png",8,8);
    field13.add_component(f13);
    gameplay.add_game_object(field13);

    GameObject field14("field14",256,128);
    field14.xF = 1;field14.yF = 1;
    ImageComponent f14(field14,"assets/sprites/tilesheet.png",8,8);
    field14.add_component(f14);
    gameplay.add_game_object(field14);

    GameObject field15("field15",256,192);
    field15.xF = 1;field15.yF = 1;
    ImageComponent f15(field15,"assets/sprites/tilesheet.png",8,8);
    field15.add_component(f15);
    gameplay.add_game_object(field15);

    GameObject field16("field16",64,256);
    field16.xF = 1;field16.yF = 1;
    ImageComponent f16(field16,"assets/sprites/tilesheet.png",8,8);
    field16.add_component(f16);
    gameplay.add_game_object(field16);

    GameObject field17("field17",128,256);
    field17.xF = 1;field17.yF = 1;
    ImageComponent f17(field17,"assets/sprites/tilesheet.png",8,8);
    field17.add_component(f17);
    gameplay.add_game_object(field17);

    GameObject field18("field18",192,256);
    field18.xF = 1;field18.yF = 1;
    ImageComponent f18(field18,"assets/sprites/tilesheet.png",8,8);
    field18.add_component(f18);
    gameplay.add_game_object(field18);

    GameObject field19("field19",256,256);
    field19.xF = 1;field19.yF = 1;
    ImageComponent f19(field19,"assets/sprites/tilesheet.png",8,8);
    field19.add_component(f19);
    gameplay.add_game_object(field19);

    GameObject field20("field20",64,320);
    field20.xF = 1;field20.yF = 1;
    ImageComponent f20(field20,"assets/sprites/tilesheet.png",8,8);
    field20.add_component(f20);
    gameplay.add_game_object(field20);

    GameObject field21("field21",128,320);
    field21.xF = 1;field21.yF = 1;
    ImageComponent f21(field21,"assets/sprites/tilesheet.png",8,8);
    field21.add_component(f21);
    gameplay.add_game_object(field21);

    GameObject field22("field22",192,320);
    field22.xF = 1;field22.yF = 1;
    ImageComponent f22(field22,"assets/sprites/tilesheet.png",8,8);
    field22.add_component(f22);
    gameplay.add_game_object(field22);

    GameObject field23("field23",256,320);
    field23.xF = 1;field23.yF = 1;
    ImageComponent f23(field23,"assets/sprites/tilesheet.png",8,8);
    field23.add_component(f23);
    gameplay.add_game_object(field23);

    GameObject field24("field24",320,320);
    field24.xF = 1;field24.yF = 1;
    ImageComponent f24(field24,"assets/sprites/tilesheet.png",8,8);
    field24.add_component(f24);
    gameplay.add_game_object(field3);

    GameObject field25("field25",320,64);
    field25.xF = 1;field25.yF = 1;
    ImageComponent f25(field25,"assets/sprites/tilesheet.png",8,8);
    field25.add_component(f25);
    gameplay.add_game_object(field25);

    GameObject field26("field26",320,128);
    field26.xF = 1;field26.yF = 1;
    ImageComponent f26(field26,"assets/sprites/tilesheet.png",8,8);
    field26.add_component(f26);
    gameplay.add_game_object(field26);

    GameObject field27("field27",320,192);
    field27.xF = 1;field27.yF = 1;
    ImageComponent f27(field27,"assets/sprites/tilesheet.png",8,8);
    field27.add_component(f27);
    gameplay.add_game_object(field27);

    GameObject field28("field28",320,256);
    field28.xF = 1;field28.yF = 1;
    ImageComponent f28(field28,"assets/sprites/tilesheet.png",8,8);
    field28.add_component(f28);
    gameplay.add_game_object(field28);

    GameObject field29("field29",384,64);
    field29.xF = 1;field29.yF = 1;
    ImageComponent f29(field29,"assets/sprites/tilesheet.png",8,8);
    field29.add_component(f29);
    gameplay.add_game_object(field29);

    GameObject field30("field30",384,128);
    field30.xF = 1;field30.yF = 1;
    ImageComponent f30(field30,"assets/sprites/tilesheet.png",8,8);
    field30.add_component(f30);
    gameplay.add_game_object(field30);

    GameObject field31("field31",384,192);
    field31.xF = 1;field31.yF = 1;
    ImageComponent f31(field31,"assets/sprites/tilesheet.png",8,8);
    field31.add_component(f31);
    gameplay.add_game_object(field31);

    GameObject field32("field32",384,256);
    field32.xF = 1;field32.yF = 1;
    ImageComponent f32(field32,"assets/sprites/tilesheet.png",8,8);
    field32.add_component(f32);
    gameplay.add_game_object(field32);

    GameObject field33("field33",384,320);
    field33.xF = 1;field33.yF = 1;
    ImageComponent f33(field33,"assets/sprites/tilesheet.png",8,8);
    field33.add_component(f33);
    gameplay.add_game_object(field33);

    GameObject field34("field34",320,320);
    field34.xF = 1;field34.yF = 1;
    ImageComponent f34(field34,"assets/sprites/tilesheet.png",8,8);
    field34.add_component(f34);
    gameplay.add_game_object(field34);

    GameObject field35("field35",128,0);
    field35.xF = 1;field35.yF = 0;
    ImageComponent f35(field35,"assets/sprites/tilesheet.png",8,8);
    field35.add_component(f35);
    gameplay.add_game_object(field35);

    GameObject field36("field36",192,0);
    field36.xF = 1;field36.yF = 0;
    ImageComponent f36(field36,"assets/sprites/tilesheet.png",8,8);
    field36.add_component(f36);
    gameplay.add_game_object(field36);

    GameObject field37("field37",256,0);
    field37.xF = 1;field37.yF = 0;
    ImageComponent f37(field37,"assets/sprites/tilesheet.png",8,8);
    field37.add_component(f37);
    gameplay.add_game_object(field37);

    GameObject field38("field38",320,0);
    field38.xF = 1;field38.yF = 0;
    ImageComponent f38(field38,"assets/sprites/tilesheet.png",8,8);
    field38.add_component(f38);
    gameplay.add_game_object(field38);

    GameObject field39("field39",384,0);
    field39.xF = 1;field39.yF = 0;
    ImageComponent f39(field39,"assets/sprites/tilesheet.png",8,8);
    field39.add_component(f39);
    gameplay.add_game_object(field39);

    GameObject field40("field40",0,128);
    field40.xF = 0;field40.yF = 1;
    ImageComponent f40(field40,"assets/sprites/tilesheet.png",8,8);
    field40.add_component(f40);
    gameplay.add_game_object(field40);

    GameObject field41("field41",0,192);
    field41.xF = 0;field41.yF = 1;
    ImageComponent f41(field41,"assets/sprites/tilesheet.png",8,8);
    field41.add_component(f41);
    gameplay.add_game_object(field41);

    GameObject field42("field42",0,256);
    field42.xF = 0;field42.yF = 1;
    ImageComponent f42(field42,"assets/sprites/tilesheet.png",8,8);
    field42.add_component(f42);
    gameplay.add_game_object(field42);

    GameObject field43("field43",0,320);
    field43.xF = 0;field43.yF = 1;
    ImageComponent f43(field43,"assets/sprites/tilesheet.png",8,8);
    field43.add_component(f43);
    gameplay.add_game_object(field43);

    GameObject field44("field44",0,384);
    field44.xF = 0;field44.yF = 2;
    ImageComponent f44(field44,"assets/sprites/tilesheet.png",8,8);
    field44.add_component(f44);
    gameplay.add_game_object(field44);

    GameObject field45("field45",64,384);
    field45.xF = 1;field45.yF = 2;
    ImageComponent f45(field45,"assets/sprites/tilesheet.png",8,8);
    field45.add_component(f45);
    gameplay.add_game_object(field45);

    GameObject field46("field46",128,384);
    field46.xF = 1;field46.yF = 2;
    ImageComponent f46(field46,"assets/sprites/tilesheet.png",8,8);
    field46.add_component(f46);
    gameplay.add_game_object(field46);

    GameObject field47("field47",192,384);
    field47.xF = 1;field47.yF = 2;
    ImageComponent f47(field47,"assets/sprites/tilesheet.png",8,8);
    field47.add_component(f47);
    gameplay.add_game_object(field47);

    GameObject field48("field48",256,384);
    field48.xF = 1;field48.yF = 2;
    ImageComponent f48(field48,"assets/sprites/tilesheet.png",8,8);
    field48.add_component(f48);
    gameplay.add_game_object(field48);

    GameObject field49("field49",320,384);
    field49.xF = 1;field49.yF = 2;
    ImageComponent f49(field49,"assets/sprites/tilesheet.png",8,8);
    field49.add_component(f49);
    gameplay.add_game_object(field49);
    
    GameObject field50("field50",384,384);
    field50.xF = 1;field50.yF = 2;
    ImageComponent f50(field50,"assets/sprites/tilesheet.png",8,8);
    field50.add_component(f50);
    gameplay.add_game_object(field50);

    GameObject field51("field51",448,384);
    field51.xF = 2;field51.yF = 2;
    ImageComponent f51(field51,"assets/sprites/tilesheet.png",8,8);
    field51.add_component(f51);
    gameplay.add_game_object(field51);

    GameObject field52("field52",448,64);
    field52.xF = 2;field52.yF = 1;
    ImageComponent f52(field52,"assets/sprites/tilesheet.png",8,8);
    field52.add_component(f52);
    gameplay.add_game_object(field52);

    GameObject field53("field53",448,128);
    field53.xF = 2;field53.yF = 1;
    ImageComponent f53(field53,"assets/sprites/tilesheet.png",8,8);
    field53.add_component(f53);
    gameplay.add_game_object(field53);

    GameObject field54("field54",448,192);
    field54.xF = 2;field54.yF = 1;
    ImageComponent f54(field54,"assets/sprites/tilesheet.png",8,8);
    field54.add_component(f54);
    gameplay.add_game_object(field54);

    GameObject field55("field55",448,256);
    field55.xF = 2;field55.yF = 1;
    ImageComponent f55(field55,"assets/sprites/tilesheet.png",8,8);
    field55.add_component(f55);
    gameplay.add_game_object(field55);

    GameObject field56("field56",448,320);
    field56.xF = 2;field56.yF = 1;
    ImageComponent f56(field56,"assets/sprites/tilesheet.png",8,8);
    field56.add_component(f56);
    gameplay.add_game_object(field56);

    GameObject field57("field57",448,0);
    field57.xF = 2;field57.yF = 0;
    ImageComponent f57(field57,"assets/sprites/tilesheet.png",8,8);
    field57.add_component(f57);
    gameplay.add_game_object(field57);

    GameObject field59("field59",0,448);
    field59.xF = 0;field59.yF = 3;
    ImageComponent f59(field59,"assets/sprites/tilesheet.png",8,8);
    field59.add_component(f59);
    gameplay.add_game_object(field59);

    GameObject field60("field60",64,448);
    field60.xF = 1;field60.yF = 3;
    ImageComponent f60(field60,"assets/sprites/tilesheet.png",8,8);
    field60.add_component(f60);
    gameplay.add_game_object(field60);

    GameObject field61("field61",128,448);
    field61.xF = 1;field61.yF = 3;
    ImageComponent f61(field61,"assets/sprites/tilesheet.png",8,8);
    field61.add_component(f61);
    gameplay.add_game_object(field61);

    GameObject field62("field62",192,448);
    field62.xF = 1;field62.yF = 3;
    ImageComponent f62(field62,"assets/sprites/tilesheet.png",8,8);
    field62.add_component(f62);
    gameplay.add_game_object(field62);

    GameObject field63("field63",256,448);
    field63.xF = 1;field63.yF = 3;
    ImageComponent f63(field63,"assets/sprites/tilesheet.png",8,8);
    field63.add_component(f63);
    gameplay.add_game_object(field63);

    GameObject field64("field64",320,448);
    field64.xF = 1;field64.yF = 3;
    ImageComponent f64(field64,"assets/sprites/tilesheet.png",8,8);
    field64.add_component(f64);
    gameplay.add_game_object(field64);

    GameObject field65("field65",384,448);
    field65.xF = 1;field65.yF = 3;
    ImageComponent f65(field65,"assets/sprites/tilesheet.png",8,8);
    field65.add_component(f65);
    gameplay.add_game_object(field65);

    GameObject field66("field66",448,448);
    field66.xF = 2;field66.yF = 3;
    ImageComponent f66(field66,"assets/sprites/tilesheet.png",8,8);
    field66.add_component(f66);
    gameplay.add_game_object(field66);


    // Game loop
    Game::instance.run();
    return 0;
}
