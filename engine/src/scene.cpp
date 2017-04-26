#include "scene.hpp"
#include "log.h"
#include <string>
#include "sdl2include.h"
using namespace engine;

GameObject INVALID_GAME_OBJECT;

bool Scene::add_game_object(GameObject & obj)
{
    auto id = obj.name();
    INFO("Add game object " << id << " to scene " << m_name);

    if (m_objects.find(id) != m_objects.end())
    {
        WARN("Game object " << id << " already exists!");
        return false;
    }

    m_objects[id] = &obj;
    return true;
}

GameObject & Scene::get_game_object(const std::string & id)
{
    if (m_objects.find(id) == m_objects.end())
    {
        WARN("Could not find game object " << id);
        return INVALID_GAME_OBJECT;
    }

    return *m_objects[id];
}

bool Scene::remove_game_object(const std::string & id)
{
    INFO("Remove game object " << id << " from scene " << m_name);

    if (m_objects.find(id) == m_objects.end())
    {
        WARN("Could not find game object " << id);
        return false;
    }

    m_objects.erase(id);
    return true;
}

bool Scene::init()
{
    INFO("Init scene " << m_name);

    for (auto id_obj: m_objects)
    {
        auto obj = id_obj.second;
        if (obj->state() == GameObject::State::enabled &&
            obj->init() == false) return false;
    }

    return true;
}

bool Scene::shutdown()
{
    INFO("Shutdown scene " << m_name);

    for (auto id_obj: m_objects)
    {
        auto obj = id_obj.second;
        if (obj->state() == GameObject::State::enabled &&
            obj->shutdown() == false) return false;
    }

    return true;
}

bool Scene::draw()
{
    for (auto id_obj: m_objects)
    {
        auto obj = id_obj.second;
        if (obj->state() == GameObject::State::enabled &&
            obj->draw() == false) return false;
    }

    return true;
}
bool Scene::update()
{
    return true;
}
bool Scene::isColliding( GameObject* a, GameObject* b )
{
    //The sides of the rectangles
    int leftA, leftB;
    int rightA, rightB;
    int topA, topB;
    int bottomA, bottomB;
    int fact = 30;
    //Calculate the sides of rect A
    leftA = a->position.getX()+fact;
    rightA = a->position.getX()+fact + a->w-fact;
    topA = a->position.getY()+fact;
    bottomA = a->position.getY()+fact + a->h-fact;

    //Calculate the sides of rect B
    leftB = b->position.getX()+fact;
    rightB = b->position.getX()+fact + b->w-fact;
    topB = b->position.getY()+fact;
    bottomB = b->position.getY()+fact + b->h-fact;
    //If any of the sides from A are outside of B
    if( bottomA <= topB )
    {
        return false;
    }
    if( topA >= bottomB )
    {
        return false;
    }
    if( rightA <= leftB )
    {
        return false;
    }
    if( leftA >= rightB )
    {
        return false;
    }
    //If none of the sides from A are outside B
    return true;
}
bool Scene::verifyColision(GameObject* ob)
{
    bool result;
    for (auto id_obj: m_objects)
    {
        if(ob != id_obj.second){
            result = isColliding(ob,id_obj.second);
            if(result){
                printf("colliding with %s\n",id_obj.second->name().c_str());
            }
        }
    }

    return result;
}