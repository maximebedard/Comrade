#include "Engine.hpp"
#include <iostream>
#include <fstream>
#include <stdexcept>

#include <cereal/types/vector.hpp>
#include <cereal/archives/json.hpp>



using namespace comrade;

Engine::Engine()
{
}

void Engine::load_config(std::string configPath)
{
  std::ifstream is(configPath);
  cereal::JSONInputArchive archive(is);
  archive(m_config);
}

void Engine::init()
{

  if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    throw new std::runtime_error(SDL_GetError());

  int flags = SDL_WINDOW_OPENGL;
  for(auto f : m_config.flags)
    flags |= f;

  m_window = SDL_CreateWindow(m_config.name.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, m_config.height, m_config.width, flags);
  if (m_window == nullptr)
    throw new std::runtime_error(SDL_GetError());

  m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
  if (m_renderer == nullptr)
    throw new std::runtime_error(SDL_GetError());

}

void Engine::cleanup()
{

  SDL_DestroyRenderer(m_renderer);
  SDL_DestroyWindow(m_window);
  SDL_Quit();

}


void Engine::run()
{
  m_running = true;

  while (m_running)
  {
    poll_events();

    SDL_RenderClear(m_renderer);
    SDL_RenderPresent(m_renderer);
  }

}

void Engine::poll_events()
{

  SDL_Event event;
  while (SDL_PollEvent(&event)) {
    switch (event.type)
    {
      case SDL_QUIT:
        m_running = false;
        break;
    }
  }

}

void Engine::start()
{
  load_config();
  try {
    init();
  }
  catch (std::runtime_error &ex){
    std::cerr << ex.what() << std::endl;
    cleanup();
    return;
  }

  run();

  cleanup();
}

void Engine::add_scene(Scene* scene)
{
  m_scenes.push_back(scene);
}
