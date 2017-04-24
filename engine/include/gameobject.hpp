#ifndef __ENGINE_GAME_OBJECT__
#define __ENGINE_GAME_OBJECT__

#include <string>
#include <list>
#include <typeindex>
#include <typeinfo>
#include <unordered_map>

#include "components/component.hpp"

namespace engine {

class GameObject {
public:
    enum class State {
        enabled,
        disabled,
        invalid
    };

    GameObject() : GameObject("",0,0, State::invalid) {}
    GameObject(std::string name,int _x,int _y, State state=State::enabled)
        : x(_x), y(_y), w(0), h(0), rotation(0), m_name(name),
          m_state(state) {}

    ~GameObject() {}

    virtual bool init();
    virtual bool shutdown();
    virtual bool update(int xInc, int yInc,int xFInc,int yFSub);
    virtual bool draw();


    bool add_component(Component & component);

    inline std::string name()  const { return m_name; }
    inline State       state() const { return m_state; }

    inline void set_size(int _w, int _h) { w = _w; h = _h; }

    int    x, y;
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
