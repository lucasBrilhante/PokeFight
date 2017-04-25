#ifndef __ENGINE_GAME_OBJECT__
#define __ENGINE_GAME_OBJECT__

#include <string>
#include <list>
#include <typeindex>
#include <typeinfo>
#include <unordered_map>

#include "vector.hpp"
#include "components/component.hpp"

namespace engine {

class GameObject {
public:
    enum class State {
        enabled,
        disabled,
        invalid
    };

    GameObject() : GameObject("",0,0,true, State::invalid) {}
    GameObject(std::string _name,int _x,int _y,bool _passable = false, State _state=State::enabled)
        : w(0), h(0), rotation(0), m_name(_name), m_passable(_passable), position(_x,_y), velocity(0,0), aceleration(0,0),
          m_state(_state) {}

    ~GameObject() {}

    virtual bool init();
    virtual bool shutdown();
    virtual bool update(Vector2D v,int xFInc,int yFSub);
    virtual bool draw();


    bool add_component(Component & component);

    inline std::string name()  const { return m_name; }
    inline State       state() const { return m_state; }
    inline bool       passable() const { return m_passable; }


    inline void set_size(int _w, int _h) { w = _w; h = _h; }
    Vector2D position;
    Vector2D velocity;
    Vector2D aceleration;

    bool m_passable;
    
    int    w, h;
    int    xF,yF;
    double rotation;

protected:
    std::string m_name;
    State       m_state;
    std::unordered_map<std::type_index, std::list<Component *> > m_components;
};

}

#endif
