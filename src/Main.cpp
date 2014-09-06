#include <iostream>
#include "Engine.hpp"
#include "Components/TransformComponent.hpp"
#include "Components/MeshComponent.hpp"
#include "Entity.hpp"
#include "Scene.hpp"


int main(int argc, char** argv)
{

  using namespace comrade;

  Engine game;

  Entity root("root");

  root.add_component(new MeshComponent("config/test1.json"));
  root.add_component(new TransformComponent(0,0,0));

  game.add_scene(new Scene(root));

  game.start();

}
