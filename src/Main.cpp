#include <iostream>
#include "Engine.hpp"
#include "Components/TransformComponent.hpp"
#include "Components/MeshComponent.hpp"
#include "Entity.hpp"
#include "Scene.hpp"

#include <chrono>


int main(int argc, char** argv)
{

  using namespace comrade;
  using namespace std;

  Engine game;

  Entity root("root");
  auto start = chrono::steady_clock::now();

  root.add_component(new MeshComponent("config/test1.json"));

  auto end = chrono::steady_clock::now();
  auto diff = end - start;
  root.add_component(new TransformComponent(0,0,0));

  cout << chrono::duration <double, milli> (diff).count() << " ms" << endl;

  game.add_scene(new Scene(root));

  game.start();

}
