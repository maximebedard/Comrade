#ifndef _MeshComponent_Comrade_H
#define _MeshComponent_Comrade_H

#include "../Component.hpp"

namespace comrade
{

  class MeshComponent : public Component
  {

  public:

    MeshComponent(std::string filePath) : m_filePath(filePath) { }

    virtual void update() {}

  private:
    std::string m_filePath;

  };

}

#endif
