#include <iostream>
class A{};
int main()
{
  std::cout << "hello world!" << std::endl;
  auto test = new A; // testing auto C++11 keyword
  if( test == nullptr ){std::cout << "hey hey" << std::endl;} // testing nullptr keyword
  else{std::cout << " the pointer is not null" << std::endl;}
  return 0;
};
