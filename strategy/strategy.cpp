#include<iostream>
#include"strategy1.h"
#include"strategy2.h"
#include"context.h"

int main()
{
  Context_ context{std::make_unique<Strategy1_>()};
  std::cout<<context.Strategy()<<std::endl;
  context.setStrategy(std::make_unique<Strategy2_>());
  std::cout<<context.Strategy()<<std::endl;
}
