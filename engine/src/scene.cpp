#include "scene.hpp"
#include "log.h"
#include <string>
#include <vector>
#include <utility>
#include "sdl2include.h"

using namespace engine;

GameObject INVALID_GAME_OBJECT;

bool Scene::comparator(const std::pair<std::string, GameObject *>  &p1, 
    const std::pair<std::string, GameObject *> &p2) 
{
    if(p1.second->name() == "mapa"){
        return true;
    }else if (p2.second->name() == "mapa"){
        return false;
    }else if (p2.second->name() == "backgroundEnd"){
        return false;
    }
    else{
        return (p1.second->physics.position.getY() + p1.second->h) <
           (p2.second->physics.position.getY() + p2.second->h);
   }
}

std::vector<std::pair<std::string, GameObject *>> Scene::sortGameObjects(){
    std::vector<std::pair<std::string, GameObject *>> mapAsVector;
    copy(m_objects.begin(), m_objects.end(), back_inserter(mapAsVector));
    sort(mapAsVector.begin(), mapAsVector.end(), comparator);
    return mapAsVector;
}

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

GameObject * Scene::get_game_object(const std::string & id)
{
    /*if (m_objects.find(id) == m_objects.end())
    {
        WARN("Could not find game object " << id);
        return INVALID_GAME_OBJECT;
    }*/

    return m_objects[id];
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
        obj->resetState();
        if (obj->init() == false) return false;
    }

    return true;
}

bool Scene::shutdown()
{
    INFO("Shutdown scene " << m_name);

    for (auto id_obj: m_objects)
    {
        auto obj = id_obj.second;
        if (obj->shutdown() == false) return false;
    }

    return true;
}

bool Scene::draw()
{
    std::vector<std::pair<std::string, GameObject *>> objectsVector = sortGameObjects();

    for (auto id_obj: objectsVector)
    {
        auto obj = id_obj.second;
        if (obj->state() == GameObject::State::enabled &&
            obj->draw() == false) return false;
    }

    return true;
}
bool Scene::update()
{
    for (auto id_obj: m_objects)
    {
        auto obj = id_obj.second;
        if (obj->state() == GameObject::State::enabled &&
            obj->update() == false) return false;
    }
    
    return true;
}
