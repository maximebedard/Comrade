#include "Entity.hpp"

using namespace comrade;



Entity::Entity(std::string name, std::string tag)
  : m_name(name), m_tag(tag)
{
}

void Entity::add_component(Component* component)
{
  m_components.push_back(component);
}

void Entity::add_entity(Entity* entity)
{
  m_entities.push_back(entity);
}

void Entity::update()
{
  for(auto &component:m_components)
  {
      component.update();
  }
}
