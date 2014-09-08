#ifndef _MeshComponent_Comrade_H
#define _MeshComponent_Comrade_H

#include "../Component.hpp"

#include <iostream>
#include <fstream>
#include <stdexcept>

#include <cereal/types/vector.hpp>
#include <cereal/archives/json.hpp>



namespace comrade
{

  struct MeshConfig
  {
    std::vector<int> coords;
    template <class Archive>
    void serialize( Archive & ar )
    {
      ar(CEREAL_NVP(coords));
    }
  };


  class MeshComponent : public Component
  {

  public:

    MeshComponent(std::string filePath)
      : m_filePath(filePath)
    {
      std::ifstream is(filePath);
      cereal::JSONInputArchive archive(is);
      archive(cereal::make_nvp("mesh", m_config));
    }

    virtual void update() {}

  private:
    std::string m_filePath;

    MeshConfig m_config;

  };

}

#endif
