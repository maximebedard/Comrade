#ifndef _Component_Comrade_H
#define _Component_Comrade_H

namespace comrade
{

  class Component : boost::noncopyable
  {

  public:

    virtual ~Component() {}

    virtual void update() = 0;

  };

}

#endif
