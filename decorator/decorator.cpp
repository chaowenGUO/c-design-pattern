#include<iostream>
#include"concrete.h"
#include"decorator1.h"
#include"decorator2.h"

int main()
{
  std::cout<<Decorator1_{std::make_unique<Decorator2_>(std::make_unique<Decorator1_>(std::make_unique<Concrete_>()))}()<<std::endl;
}
