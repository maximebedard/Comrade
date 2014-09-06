#ifndef _Comrade_Scene_H
#define _Comrade_Scene_H

#include <boost/utility.hpp>
#include <memory>

#include "Entity.hpp"

namespace comrade
{

  class Scene : boost::noncopyable
  {

  public:
    Scene(Entity& root);

    const Entity& root() const { return m_root; }

  private:

    Entity& m_root;

  };

}

#endif
