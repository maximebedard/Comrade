#ifndef _Comrade_Engine_H
#define _Comrade_Engine_H

#include <string>
#include <vector>

#include <cereal/types/common.hpp>

#include <SDL.h>

#include <boost/ptr_container/ptr_vector.hpp>

#include <boost/utility.hpp>

#include "Scene.hpp"

namespace comrade
{

  struct EngineConfig
  {

    std::string name = "Comrade";
    int height = 640;
    int width = 480;
    std::vector<int> flags;

    template <class Archive>
    void serialize( Archive & ar )
    {
      ar(CEREAL_NVP(name),
        CEREAL_NVP(height),
        CEREAL_NVP(width),
        CEREAL_NVP(flags));
    }

  };


  class Engine : boost::noncopyable
  {

  public:
    Engine();

    void start();

    void add_scene(Scene* scene);

  private:

    void run();

    void init();

    void poll_events();

    void cleanup();

    void load_config(std::string configPath = "config/config.json");

    SDL_Window* m_window;

    SDL_Renderer* m_renderer;

    EngineConfig m_config;

    bool m_running;

    boost::ptr_vector<Scene> m_scenes;

  };


}

#endif
