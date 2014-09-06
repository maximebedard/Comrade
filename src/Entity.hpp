#ifndef _Comrade_Entity_H
#define _Comrade_Entity_H


#include <string>
#include <memory>
#include <iostream>
#include <boost/utility.hpp>
#include <boost/ptr_container/ptr_vector.hpp>

#include "Component.hpp"

namespace comrade
{


  class Entity
  {

  public:

    Entity(std::string name = "", std::string tag = "");

    virtual ~Entity() {}

    void add_component(Component* component);

    void add_entity(Entity* entity);

    std::string name() const { return m_name; }
    std::string tag() const { return m_tag; }

    void update();

  private:

    boost::ptr_vector<Component> m_components;
    boost::ptr_vector<Entity> m_entities;

    std::string m_name;
    std::string m_tag;


  };

}

#endif
