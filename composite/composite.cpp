#include"leaf1.h"
#include"leaf2.h"
#include"composite.h"
#include<iostream>

int main()
{
  Composite_ composite1,composite2;
  composite1.emplace_back(std::make_unique<Leaf1_>());
  composite1.emplace_back(std::make_unique<Leaf2_>());
  composite2.emplace_back(std::make_unique<Composite_>(composite1));
  composite2.emplace_back(std::make_unique<Leaf1_>());
  std::cout<<composite1()<<std::endl;
  std::cout<<composite2()<<std::endl;
}

//exception constructor remove
