#ifndef _TransformComponent_Comrade_H
#define _TransformComponent_Comrade_H

#include <LinearMath/btVector3.h>
#include "../Component.hpp"



namespace comrade
{

  class TransformComponent : public Component
  {

  public:
    TransformComponent(float x, float y, float z)
      : m_position(btVector3(x,y,z))
    {
    }

    TransformComponent(const btVector3& position) : m_position(position)
    {
    }

    virtual void update() {}

  private:
    btVector3 m_position;



  };

}


#endif
